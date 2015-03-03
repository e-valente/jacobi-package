#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

extern int total_processes, dim;

int main(int argc, char **argv) {
    
  if (argc < 3) {
    fprintf (stderr, "Usage: %s <dimension> <number of processes> [left, top, right, EPSILON] \n", argv[0]);
    exit(1);
    
  }
  
  handleInput(argc, argv);
  createMatrix(dimension);
  
  printMatrix(dimension);
  
  
  destroyMatrix(dimension);
  return 0;
}
