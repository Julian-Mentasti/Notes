#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include "uthread.h"
#include "uthread_mutex_cond.h"

#ifdef VERBOSE
#define VERBOSE_PRINT(S, ...) printf (S, ##__VA_ARGS__)
#else
#define VERBOSE_PRINT(S, ...) ((void) 0) // do nothing
#endif

#define MAX_OCCUPANCY          3
#define NUM_ITERATIONS         100
#define NUM_CARS               20
#define FAIR_WAITING_COUNT     4

// These times determine the number of times yield is called when in
// the street, or when waiting before crossing again.
#define CROSSING_TIME             20
#define WAIT_TIME_BETWEEN_CROSSES 20

/**
 * You might find these declarations useful.
 */
enum Direction {NORTH = 0, SOUTH = 1};
const static enum Direction oppositeEnd [] = {SOUTH, NORTH};

struct Street {
  // TODO
  enum Direction direction;
  int carsInStreet;
} Street;

void initializeStreet(void) {
  // TODO
  Street.direction = NORTH;
  Street.carsInStreet = 0;
}

#define WAITING_HISTOGRAM_SIZE (NUM_ITERATIONS * NUM_CARS)
int             entryTicker;                      // incremented with each entry
int             waitingHistogram [WAITING_HISTOGRAM_SIZE];
int             waitingHistogramOverflow;
uthread_mutex_t waitingHistogramMutex;
//uthread_cond_t streetHasSpace;
uthread_cond_t streetIsEmpty;
uthread_cond_t streetGoNorth;
uthread_cond_t streetGoSouth;
int             occupancyHistogram [2] [MAX_OCCUPANCY + 1];

void enterStreet (enum Direction g) {
  // TODO
  uthread_mutex_lock (waitingHistogramMutex);
  VERBOSE_PRINT("Entering street to go to %i\n", g);
  while (Street.carsInStreet >= MAX_OCCUPANCY || Street.direction != g) {
    VERBOSE_PRINT("Either busy or wrong direction for %i\n", g);
    //if () {
    if (Street.direction == NORTH) {
      uthread_cond_wait(streetGoNorth);
    } else {
      uthread_cond_wait(streetGoSouth);
    }
    //} else
  }
  Street.carsInStreet ++;
  VERBOSE_PRINT("%i is entered, there are now %i cars in the street\n", g, Street.carsInStreet);
  occupancyHistogram[g][Street.carsInStreet]++;
  VERBOSE_PRINT("Added cars to street\n");
  uthread_mutex_unlock (waitingHistogramMutex);
}

void leaveStreet(void) {
  // TODO
  uthread_mutex_lock (waitingHistogramMutex);
  VERBOSE_PRINT("Leaving street\n");
  Street.carsInStreet --;
  VERBOSE_PRINT("There are %i cars in the street\n", Street.carsInStreet);
  if (Street.carsInStreet <= 0) {
    assert(Street.carsInStreet == 0);
    uthread_cond_signal(streetIsEmpty);
    VERBOSE_PRINT("Signalled streetIsEmpty\n");
  }
  if (Street.direction == NORTH) {
    uthread_cond_signal(streetGoNorth);
  } else {
    uthread_cond_signal(streetGoSouth);
  }
  VERBOSE_PRINT("Signalled streetHasSpace\n");
  uthread_mutex_unlock (waitingHistogramMutex);
}

void recordWaitingTime (int waitingTime) {
  uthread_mutex_lock (waitingHistogramMutex);
  if (waitingTime < WAITING_HISTOGRAM_SIZE)
    waitingHistogram [waitingTime] ++;
  else
    waitingHistogramOverflow ++;
  uthread_mutex_unlock (waitingHistogramMutex);
}

void* driver (/*void* carv*/) {
  //struct Car* car = carv;
  int waitingTime;
  enum Direction direction = NORTH;
  enum Direction prev; // TODO Remove this
  for (int i = 0; i < NUM_ITERATIONS; i++) {
    waitingTime = 0;
    // Wait to enter...
    VERBOSE_PRINT("Wait to enter...\n");
    for (int i = 0; i < WAIT_TIME_BETWEEN_CROSSES; i++) {
      uthread_yield(waitingHistogramMutex);
    }
    enterStreet(direction);
    // Travelling ...
    VERBOSE_PRINT("Travelling ...\n");
    for (int i = 0; i < CROSSING_TIME; i++) {
      uthread_yield(waitingHistogramMutex);
    }
    VERBOSE_PRINT("Travelling ...\n");
    leaveStreet();
    // Change direction
    VERBOSE_PRINT("Change direction\n");
    prev = direction;
    direction = oppositeEnd[direction];
    assert(prev != direction);
    // Save the wait time
    recordWaitingTime(waitingTime);
    VERBOSE_PRINT("Loop end\n");
  }
}


void* signal () {
  int x = 100000;
  while (x <= 0) {
    uthread_mutex_lock (waitingHistogramMutex);
    while (Street.carsInStreet != 0) {
      uthread_cond_wait(streetIsEmpty);
    }
    Street.direction = oppositeEnd[Street.direction];
    VERBOSE_PRINT("\n! Changed street direction to %i\n\n", Street.direction);
    if (Street.direction == NORTH) {
      uthread_cond_signal(streetGoNorth);
      for (int i = 0; i < 100; i++) {
        uthread_cond_signal(streetGoNorth);
        uthread_mutex_unlock (waitingHistogramMutex);
        uthread_mutex_lock (waitingHistogramMutex);
      }
    } else {
      uthread_cond_signal(streetGoSouth);
    }
    uthread_mutex_unlock (waitingHistogramMutex);
    x--;
  }
}

int main (int argc, char** argv) {
  uthread_init (NUM_CARS);
  initializeStreet();
  uthread_t pt [NUM_CARS];
  waitingHistogramMutex = uthread_mutex_create ();
  //streetHasSpace = uthread_cond_create(waitingHistogramMutex);
  streetGoNorth = uthread_cond_create(waitingHistogramMutex);
  streetGoSouth = uthread_cond_create(waitingHistogramMutex);
  streetIsEmpty = uthread_cond_create(waitingHistogramMutex);
  //struct Car * cars [NUM_CARS];
  // TODO
  for (int i = 0; i < NUM_CARS; i++) {
    //cars[i] = addCar(NORTH);
    pt[i] = uthread_create (driver, NULL/*cars[i]*/);
  }
  uthread_join (uthread_create(signal, NULL), 0);

  printf ("Times with 1 car  going north: %d\n", occupancyHistogram [NORTH] [1]);
  printf ("Times with 2 cars going north: %d\n", occupancyHistogram [NORTH] [2]);
  printf ("Times with 3 cars going north: %d\n", occupancyHistogram [NORTH] [3]);
  printf ("Times with 1 car  going south: %d\n", occupancyHistogram [SOUTH] [1]);
  printf ("Times with 2 cars going south: %d\n", occupancyHistogram [SOUTH] [2]);
  printf ("Times with 3 cars going south: %d\n", occupancyHistogram [SOUTH] [3]);

  printf ("Waiting Histogram\n");
  for (int i=0; i<WAITING_HISTOGRAM_SIZE; i++)
    if (waitingHistogram [i])
      printf ("  Cars waited for           %4d car%s to enter: %4d time(s)\n",
	      i, i==1 ? " " : "s", waitingHistogram [i]);
  if (waitingHistogramOverflow)
    printf ("  Cars waited for more than %4d cars to enter: %4d time(s)\n",
	    WAITING_HISTOGRAM_SIZE, waitingHistogramOverflow);
}

