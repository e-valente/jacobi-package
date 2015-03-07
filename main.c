#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "utils.h"
#include "jacobi_thread.h"
#include "jacobi_sequential.h"

extern int total_processes, dimension;

int main(int argc, char **argv) {
  struct timeval startTime, endTime, responseTime;
  int total_iters;
  char* outputFilename = "JacobiResults.txt";
  FILE* outputFile;
    
  if (argc < 3) {
    fprintf (stderr, "Usage: %s <dimension> <number of processes> [left, right, top, bottom, EPSILON] \n", argv[0]);
    exit(1);   
  }
  
  handleInput(argc, argv);
  createMatrix(dimension);
  
  pthread_barrier_init(&our_barrier,NULL,total_processes);
  /****Jacobi Thread Execution***/
  gettimeofday(&startTime, NULL);
  total_iters = jacobi_thread();
  pthread_barrier_destroy(&our_barrier);
  gettimeofday(&endTime, NULL);
  /************************/
  
  /****Jacobi Sequential Execution**
  gettimeofday(&startTime, NULL);
  total_iters = jacobi_sequential();
  gettimeofday(&endTime, NULL);
  ************************/
  
  /*Print outputs to a file*/
  outputFile = fopen(outputFilename, "w");
  printAttributes(outputFile);
  fprintf(outputFile, "%-8s = %d\n", "Taken Iters", total_iters);  
  calculateDeltaTime(startTime, endTime, &responseTime);
  fprintf(outputFile, "%s = %ld seconds, %ld microseconds\n\n", \
    "Execution Time", responseTime.tv_sec, responseTime.tv_usec);
  printMatrix(outputFile);
  
  /*close file descriptors and 
   * free memory*/
  fclose(outputFile);
  destroyMatrix(dimension);
  return 0;
}
