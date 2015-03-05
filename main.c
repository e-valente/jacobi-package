#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


#include "utils.h"
#include "jacobi-sequential.h"

extern int total_processes, dimension;

int main(int argc, char **argv) {
  struct timeval startTime, endTime, responseTime;
    
  if (argc < 3) {
    fprintf (stderr, "Usage: %s <dimension> <number of processes> [left, right, top, bottom, EPSILON] \n", argv[0]);
    exit(1);
    
  }
  
  handleInput(argc, argv);
  createMatrix(dimension);
  
  gettimeofday(&startTime, NULL);
  /****Jacobi Execution***/
  jacobi_sequential();
  gettimeofday(&endTime, NULL);

  
  printStatus();
  calculateDeltaTime(startTime, endTime, &responseTime);
  fprintf(stdout, "%s = %ld seconds, %ld microseconds\n", "execution time", responseTime.tv_sec, responseTime.tv_usec);

 
  printMatrix(dimension);
  destroyMatrix(dimension);
  return 0;
}
