#include <sys/param.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "utils.h"
#include "jacobi_thread.h"


int jacobi_thread() {
  
  pthread_attr_t attr;
  pthread_t threadid[total_processes];
  struct thread_args thread_args[total_processes];
  
  for(int i = 0; i < total_processes; i++)maxdiff[i] = 0.0;
  height = dimension / total_processes;
  
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
  
  for(int i = 0; i < total_processes; i++) {
    thread_args[i].arg1 = i +1;
    pthread_create(&threadid[i], &attr, jacobi_thread_worker, (void*) &thread_args[i]);
  }
  
  for(int j = 0; j < total_processes; j++) 
     pthread_join(threadid[j], NULL);  
  
  return 0; /*iters*/
}

void* jacobi_thread_worker(void* arg) {
  struct thread_args args = *((struct thread_args *)arg);
  int w = args.arg1;
  double mydiff = 0.0;
  fprintf(stderr, "->>> %d\n", args.arg1);
  //int firstRow = (w-1) * height + 1;
  int firstRow, lastRow;
  
  if(w == 1) {
    firstRow = (w-1) * height + 1;
    lastRow = firstRow + height -1;
  }
  else if (w == total_processes) {
    firstRow = (w-1) * height;
    lastRow = firstRow + height - 1;
    
  }
  else {
    firstRow = (w-1) * height;
    lastRow = firstRow + height;
  }
  

   fprintf(stderr, "thread %d first %d last %d\n", w, firstRow, lastRow);
   //return 0;
  
  /*******************
   * BARRIER
   * 
   * ****************/
  pthread_barrier_wait(&our_barrier);
  
  for(int iters = 1; iters < 100; iters++) {
    for(int i = firstRow; i < lastRow; i++) {
      for(int j = 1; j < dimension -1; j++) {
	newmatrix[i][j] = (matrix[i-1][j] + matrix[i+1][j] +
		      matrix[i][j-1] + matrix[i][j+1]) * 0.25;
      }
    }
       
   pthread_barrier_wait(&our_barrier);
    
    for(int i = firstRow; i < lastRow; i++) {
      for(int j = 1; j < dimension -1; j++) {
	matrix[i][j] = (newmatrix[i-1][j] + newmatrix[i+1][j] +
		      newmatrix[i][j-1] + newmatrix[i][j+1]) * 0.25;
      }
      
    }
    
    
    /*******************
    * BARRIER
      * 
    * ****************/
    pthread_barrier_wait(&our_barrier);
    fprintf(stdout, "->> iter %d\n", iters);
   }
  
  for(int i = firstRow; i < lastRow; i++) {
      for(int j = 1; j < dimension -1; j++) 
	mydiff = MAX(mydiff, dabs(matrix[i][j] - newmatrix[i][j]));
		      
  }
  
  maxdiff[w] = mydiff;
  if(maxdiff[w] < epsilon)
    return 0;
  
  /*******************
   * BARRIER
   * 
   * ****************/
  pthread_barrier_wait(&our_barrier);
 
  
  
  
  return 0;
}

  
  