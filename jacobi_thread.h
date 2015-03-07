#ifndef _JACOBI_THREAD_H
#define _JACOBI_THREAD_H
#endif

#include "utils.h"
#include <pthread.h>

#define MAX_PROCESSES 32
pthread_barrier_t our_barrier;

struct thread_args {
  int arg1;
  int arg2;
  int arg3;
};

double maxdiff[MAX_PROCESSES];
int height;

/*return total iters used*/
int jacobi_thread();
void* jacobi_thread_worker(void*);