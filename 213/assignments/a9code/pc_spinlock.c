#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "uthread.h"
#include "uthread_mutex_cond.h"
#include "spinlock.h"

#define MAX_ITEMS      10
#define NUM_ITERATIONS 200
#define NUM_CONSUMERS  2
#define NUM_PRODUCERS  2
#define NUM_THREADS    (NUM_CONSUMERS + NUM_PRODUCERS)

int producer_wait_count;     // # of times producer had to wait
int consumer_wait_count;     // # of times consumer had to wait
int histogram [MAX_ITEMS+1]; // histogram [i] == # of times list stored i items

int items = 0;

void produce(void) {
  // TODO
}

void consume(void) {
  // TODO
}


void *producer(void *a) {
  for (int i=0; i < NUM_ITERATIONS; i++)
    produce();
  return 0;
}

void *consumer(void *a) {
  for (int i=0; i< NUM_ITERATIONS; i++)
    consume();
  return 0;
}

int main (int argc, char** argv) {
  uthread_t t[NUM_THREADS];

  uthread_init(NUM_THREADS);
  
  // TODO: Create Threads and Join
  
  printf("Producer wait: %d\nConsumer wait: %d\n\n",
         producer_wait_count, consumer_wait_count);
  
  printf ("Items value histogram:\n");
  int sum = 0;
  for (int i = 0; i <= MAX_ITEMS; i++) {
    printf ("  items=%2d, %4d times\n", i, histogram [i]);
    sum += histogram [i];
  }
  assert (sum == NUM_THREADS * NUM_ITERATIONS);
}
