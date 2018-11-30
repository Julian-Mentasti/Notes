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
  uthread_mutex_t mutex;
  int nCar;
  int count;
  enum Direction dir;
  uthread_cond_t north;
  uthread_cond_t south;
} Street;

void initializeStreet(void) {
  Street.mutex = uthread_mutex_create();
  Street.north = uthread_cond_create(Street.mutex);
  Street.south = uthread_cond_create(Street.mutex);
  Street.dir = 0; // North
  Street.nCar = 0;
  Street.count = 0;
}

#define WAITING_HISTOGRAM_SIZE (NUM_ITERATIONS * NUM_CARS)
int             entryTicker;                                          // incremented with each entry
int             waitingHistogram [WAITING_HISTOGRAM_SIZE];
int             waitingHistogramOverflow;
uthread_mutex_t waitingHistogramMutex;
int             occupancyHistogram [2] [MAX_OCCUPANCY + 1];

void recordWaitingTime (int waitingTime) {
  uthread_mutex_lock (waitingHistogramMutex);
  if (waitingTime < WAITING_HISTOGRAM_SIZE)
    waitingHistogram [waitingTime] ++;
  else
    waitingHistogramOverflow ++;
  uthread_mutex_unlock (waitingHistogramMutex);
}
void singalCar(enum Direction d, int n) {
    for (int i = 0; i < n; i++) {
        if (d == SOUTH) {
            uthread_cond_signal(Street.south);
        } else if (d == NORTH) {
            uthread_cond_signal(Street.north);
        }
    }
}


void waitDir(enum Direction d) {
    if (d == SOUTH) {
        uthread_cond_wait(Street.south);
    } else if (d == NORTH) {
        uthread_cond_wait(Street.north);
    }
}

void enterStreet (enum Direction g) {
  uthread_mutex_lock(Street.mutex);
  // Julian Start
  if (Street.nCar==0) {
      Street.dir = g;
  } else {
      int iCurrent_time = Street.count;
      waitDir(g);
      int waitingTime = Street.count - iCurrent_time;
      if (waitingTime < WAITING_HISTOGRAM_SIZE) {
          waitingHistogram [waitingTime]++;
      } else {
          waitingHistogramOverflow ++;
      }
      recordWaitingTime(waitingTime);
  }
  Street.count++;
  Street.nCar++;
  occupancyHistogram[g][Street.count]++;
  uthread_mutex_unlock(Street.mutex);
}

void leaveStreet(void) {
    uthread_mutex_lock(Street.mutex);
    Street.nCar--;
    occupancyHistogram[Street.dir][Street.nCar]++;
    if (Street.nCar == 0) {
        Street.dir = oppositeEnd[Street.dir];
        for (int i=0; i<MAX_OCCUPANCY; i++) {
            singalCar(Street.dir, 1);
        }
    }
    singalCar(Street.dir,1);
    uthread_mutex_unlock(Street.mutex);
}

void* car(){
  enum Direction dir = random() % 2;
  for (int i=0; i<NUM_ITERATIONS; i++){
    enterStreet((dir+1)%2);
    for (int i=0; i<CROSSING_TIME; i++) {
      uthread_yield();
    }
    leaveStreet();
    for (int i=0; i<WAIT_TIME_BETWEEN_CROSSES; i++) {
      uthread_yield();
    }
  }
}

int main (int argc, char** argv) {
  uthread_init (NUM_CARS);
  initializeStreet();
  uthread_t pt [NUM_CARS];
  waitingHistogramMutex = uthread_mutex_create ();

  for (int i=0; i<NUM_CARS; i++) {
    pt[i] = uthread_create(car,NULL);
  }

  for (int i=0; i<NUM_CARS; i++) {
    uthread_join(pt[i],0);
  }
  
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
  printf ("DONE!\n");
}
