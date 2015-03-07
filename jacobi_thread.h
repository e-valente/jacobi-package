#ifndef _JACOBI_THREAD_H
#define _JACOBI_THREAD_H
#endif

#include "utils.h"

struct thread_args {
  int arg1;
  int arg2;
  int arg3;
};

/*return total iters used*/
int jacobi_thread();
void* jacobi_thread_worker(void*);