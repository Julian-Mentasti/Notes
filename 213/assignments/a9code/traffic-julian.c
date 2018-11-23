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
    int iCars;
    int iTimer;
    uthread_mutex_t mutex;
    uthread_cond_t north;
    uthread_cond_t south;
    enum Direction direction;
} Street;

struct Street* initializeStreet() {
    struct Street* street = malloc(sizeof (struct Street));
    street->mutex = uthread_mutex_create();
    street->north = uthread_cond_create(street->mutex);
    street->south = uthread_cond_create(street->mutex);
    street->direction = 1; // south
    street->iCars = 0;
    street->iTimer = 0;
    return street;
}

#define WAITING_HISTOGRAM_SIZE (NUM_ITERATIONS * NUM_CARS)
int             entryTicker;                                          // incremented with each entry
int             waitingHistogram [WAITING_HISTOGRAM_SIZE];
int             waitingHistogramOverflow;
uthread_mutex_t waitingHistogramMutex;
int             occupancyHistogram [2] [MAX_OCCUPANCY + 1];

// My Garbage:
uthread_cond_t uStreetIsNorth;
// End of my garbage - not really. 
// it has no end.

// Handle Car Signaling
void signalCar(struct Street* s, enum Direction d, int n) {
    for (int i = 0; i < n; i++) {
        if (d == SOUTH) {
            uthread_cond_signal(s->south);
        } else if (d == NORTH) {
            uthread_cond_signal(s->north);
        }
    }
}

// Handle Car waiting
void waitDir(struct Street* s, enum Direction d) {
    if (d == SOUTH) {
        uthread_cond_wait(s->south);
    } else if (d == NORTH) {
        uthread_cond_wait(s->north);
    }
}

void enterStreet (struct Street* s, enum Direction g) {
    uthread_mutex_lock(s->mutex);
    if (s->iCars == 0) {
        s->direction = g;
    } else {
        int iCurrent_time = s->iTimer;
        waitDir(s, g);
        int waitingTime = s->iTimer - iCurrent_time;
        if (waitingTime < WAITING_HISTOGRAM_SIZE) {
            waitingHistogram [waitingTime] ++;
        } else {
            waitingHistogramOverflow ++ ;
        }
    }

    s->iTimer++;
    s->iCars++;
    occupancyHistogram[g][s->iTimer]++;
    uthread_mutex_unlock(s->mutex);
}

void leaveStreet(struct Street* s) {
    uthread_mutex_lock(s->mutex);
    s->iCars--;
    occupancyHistogram[s->direction][s->iCars]++;
    if (s->iCars == 0) {
        s->direction = oppositeEnd[s->direction];
        signalCar(s, s->direction, 3);
    }
    uthread_mutex_unlock(s->mutex);
}

void recordWaitingTime (int waitingTime) {
  uthread_mutex_lock (waitingHistogramMutex);
  if (waitingTime < WAITING_HISTOGRAM_SIZE)
    waitingHistogram [waitingTime] ++;
  else
    waitingHistogramOverflow ++;
  uthread_mutex_unlock (waitingHistogramMutex);
}

void* car (void* av) {
    struct Street* s = av;
    enum Direction dir = random() % 2;
    for (int i = 0; i<NUM_ITERATIONS; i++) {
        enterStreet(s, dir);
        for (int i = 0; i < NUM_CARS; i++) {
            uthread_yield();
        }
        leaveStreet(s);
        for (int i = 0; i < NUM_CARS; i++) {
            uthread_yield();
        }
    }
}

//
// TODO
// You will probably need to create some additional procedures etc.
//

int main (int argc, char** argv) {
  uthread_init (NUM_CARS);
  struct Street* street = initializeStreet();
  uthread_t pt [NUM_CARS];
  waitingHistogramMutex = uthread_mutex_create ();

  for (int i = 0; i<NUM_CARS; i++) {
      pt[i] = uthread_create(car, street);
  }
  for (int i = 0; i<NUM_CARS; i++) {
      uthread_join(pt[i], 0);
  }
  
  printf ("Times with 1 car  going north: %d\n", occupancyHistogram [NORTH] [1]);
  printf ("Times with 2 cars going north: %d\n", occupancyHistogram [NORTH] [2]);
  printf ("Times with 3 cars going north: %d\n", occupancyHistogram [NORTH] [3]);
  printf ("Times with 1 car  going south: %d\n", occupancyHistogram [SOUTH] [1]);
  printf ("Times with 2 cars going south: %d\n", occupancyHistogram [SOUTH] [2]);
  printf ("Times with 3 cars going south: %d\n", occupancyHistogram [SOUTH] [3]);
  
  printf ("Waiting Histogram\n");
  printf ("hello");
  for (int i=0; i<WAITING_HISTOGRAM_SIZE; i++)
    if (waitingHistogram [i])
      printf ("  Cars waited for           %4d car%s to enter: %4d time(s)\n",
	      i, i==1 ? " " : "s", waitingHistogram [i]);
  if (waitingHistogramOverflow)
    printf ("  Cars waited for more than %4d cars to enter: %4d time(s)\n",
	    WAITING_HISTOGRAM_SIZE, waitingHistogramOverflow);
}
