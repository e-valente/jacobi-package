#include <sys/param.h>

#include "utils.h"
#include "jacobi-sequential.h"


void jacobi_sequential() {
  int i, j, k;
  double maxdiff;
  
   /****Jacobi Execution***/
  for(k = 0; k < MAXITERS; k++) {
    /*compute new values for all interior points*/
    for(i = 1; i < dimension -1; i++) { 
      for(j = 1; j < dimension -1; j++)
	newmatrix[i][j] = (matrix[i-1][j] + matrix[i+1][j] +
		      matrix[i][j-1] + matrix[i][j+1]) * 0.25;
      
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
}
  
  