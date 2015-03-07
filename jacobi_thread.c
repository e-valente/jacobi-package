#include <sys/param.h>
#include <stdio.h>
#include <pthread.h>

#include "utils.h"
#include "jacobi_thread.h"


int jacobi_thread() {
  int height = dimension / total_processes;
  double maxdiff[total_processes];
  int i;
  double mymaxdiff;
  pthread_attr_t attr;
  pthread_t threadid[total_processes];
  struct thread_args thread_args[total_processes];
  
  for (i = 0; i < total_processes; i++)maxdiff[i] = 0.0;
  
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
  
  for(i = 0; i < total_processes; i++) {
    thread_args[i].arg1 = i;
    pthread_create(&threadid[i], &attr, jacobi_thread_worker, (void*) &thread_args[i]);
  }
  
  for(int j = 0; j < total_processes; j++) 
     pthread_join(threadid[j], NULL);  
  
  return 0; /*iters*/
}

void* jacobi_thread_worker(void* arg) {
  struct thread_args args = *((struct thread_args *)arg);
  
  fprintf(stdout, "->>> %d\n", args.arg1);
  return 0;
}

  
  