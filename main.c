#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>

#include "utils.h"

extern int total_processes, dimension;

int main(int argc, char **argv) {
  int i, j, k;
  double maxdiff;
    
  if (argc < 3) {
    fprintf (stderr, "Usage: %s <dimension> <number of processes> [left, top, right, EPSILON] \n", argv[0]);
    exit(1);
    
  }
  
  handleInput(argc, argv);
  createMatrix(dimension);
  
  /****Jacobi Execution***/
  for(k = 0; k < MAXITERS; k++) {
    /*compute new values for all interior points*/
    for(i = 1; i < dimension -1; i++) { 
      for(j = 1; j < dimension -1; j++)
	newmatrix[i][j] = (matrix[i-1][j] + matrix[i+1][j] +
		      matrix[i][j-1] + matrix[i][j+1]) / 4;
      
    }
    
    maxdiff = 0.0;
    
    for(i = 1; i < dimension -1; i++) { 
      for(j = 1; j < dimension -1; j++)
	maxdiff = MAX(maxdiff, dabs(newmatrix[i][j] - matrix[i][j]));
    }
    
    /*check for termination*/
    if(maxdiff < epsilon)
      break;
    
    /*copy new grid to prepare for new update*/
    for(i = 1; i < dimension -1; i++) { 
     for(j = 1; j < dimension -1; j++)
	matrix[i][j] = newmatrix[i][j];
    }    
    
  }
  
  printMatrix(dimension);
  destroyMatrix(dimension);
  return 0;
}
