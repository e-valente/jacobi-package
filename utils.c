#include <stdlib.h>
#include <stdio.h>

#include "utils.h"


void createMatrix(int dimension) {
  
  matrix = (double**)malloc(sizeof(double*) * dimension);
  
  for (int i = 0; i < dimension; i++) 
    matrix[i] = (double*)malloc(sizeof(double) * dimension);
  
  //left, right
  for (int i = 0; i < dimension; i++) {
    //left
    matrix[i][0] = LEFT;
    //right
    matrix[i][dimension -1] = RIGHT; 
    //top
    matrix[0][i] = TOP;
    //bottom
    matrix[dimension -1][i] = BOTTOM;
    
    if ((i > 0) && (i < dimension -1)) {
    for(int j = 1; j < dimension -1; j++) 
      matrix[i][j] = MIDDLE;
    }
      
  }
  
}

void printMatrix(int dimension) {
  
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++)
      printf("%lf ", matrix[i][j]);
    printf("\n");
  }
   
  
  
}
void destroyMatrix(int dimension) {
  
  for (int i = 0; i < dimension; i++) 
    free(matrix[i]);
  
  free(matrix);
  
}
