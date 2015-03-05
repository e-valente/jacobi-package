#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include "utils.h"


void createMatrix( ) {
  
  matrix = (double**)malloc(sizeof(double*) * dimension);
  newmatrix = (double**)malloc(sizeof(double*) * dimension);
  
  for (int i = 0; i < dimension; i++) {
    matrix[i] = (double*)malloc(sizeof(double) * dimension);
    newmatrix[i] = (double*)malloc(sizeof(double) * dimension);
  }
  
  //left, right
  for (int i = 0; i < dimension; i++) {
    //left
    matrix[i][0] = left;
    //right
    matrix[i][dimension -1] = right; 
    //top
    matrix[0][i] = top;
    //bottom
    matrix[dimension -1][i] = bottom;
    
    if ((i > 0) && (i < dimension -1)) {
    for(int j = 1; j < dimension -1; j++) 
      matrix[i][j] = middle;
    }
      
  }
  
}

void printMatrix( ) {
  
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++)
      printf("%lf ", matrix[i][j]);
    printf("\n");
  }
   
  
  
}
void destroyMatrix( ) {
  
  for (int i = 0; i < dimension; i++) {
    free(matrix[i]);
    free(newmatrix[i]);
  }
  free(matrix);
  free(newmatrix);
  
}

void handleInput(int argc, char **argv) {
  
  switch (argc) {
    case 8:
      left = atoi(argv[3]) * 1.0;
      right = atoi(argv[4]) * 1.0;
      top = atoi(argv[5]) * 1.0;
      bottom = atoi(argv[6]) * 1.0;
      epsilon = atoi(argv[7]) * 1.0;
      break;
      
    case 7:
      left = atoi(argv[3]) * 1.0;
      right = atoi(argv[4]) * 1.0;
      top = atoi(argv[5]) * 1.0;
      bottom = atoi(argv[6]) * 1.0;
      epsilon = EPSILON;
      break;
    
   case 6:
      left = atoi(argv[3]) * 1.0;
      right = atoi(argv[4]) * 1.0;
      top = atoi(argv[5]) * 1.0;
      bottom = BOTTOM;
      epsilon = EPSILON;
      break;
      
  case 5:
      left = atoi(argv[3]) * 1.0;
      right = atoi(argv[4]) * 1.0;
      top = TOP;
      bottom = BOTTOM;
      epsilon = EPSILON;
      break;
      
 case 4:
      left = atoi(argv[3]) * 1.0;
      right = RIGHT;
      top = TOP;
      bottom = BOTTOM;
      epsilon = EPSILON;
      break;    
 
 default:
    left = LEFT;
    right = RIGHT;
    top = TOP;
    bottom = BOTTOM;
    epsilon = EPSILON;
    break;    
     
  }
  
  middle = MIDDLE;
  dimension = atoi(argv[1]);
  total_processes = atoi(argv[2]);
  
}


double dabs(double a) {
  
  if (a < 0.000000000) return -a;
  else return a;
  
}
void printStatus() {
  
  fprintf(stdout, "%-8s = %d x %d\n", "Grid", dimension, dimension);
  fprintf(stdout, "%-8s = %d\n", "numProcs", total_processes);
  fprintf(stdout, "%-8s = %.4lf\n", "left", left);
  fprintf(stdout, "%-8s = %.4lf\n", "right", right);
  fprintf(stdout, "%-8s = %.4lf\n", "top", top);
  fprintf(stdout, "%-8s = %.4lf\n", "bottom", bottom);
  fprintf(stdout, "%-8s = %.4lf\n", "epsilon", epsilon);  
  fprintf(stdout, "\n\n");
}

void calculateDeltaTime(struct timeval start, struct timeval end, struct timeval *res) {
  int seconds;
  int usecs;
  
  seconds = end.tv_sec - start.tv_sec;
  usecs = end.tv_usec - start.tv_usec;
  
  if(end.tv_usec < start.tv_usec) {
    seconds--;
    usecs += 1000000;
  }
  
  res->tv_sec = seconds;
  res->tv_usec = usecs;
  
}
