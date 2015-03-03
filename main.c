#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int main(int argc, char **argv) {
    
  int dim, total_processes;
  
  if (argc < 3) {
    fprintf (stderr, "Usage: %s <dimension> <number of processes> [left, top, right, EPSILON] \n", argv[0]);
    exit(1);
    
  }
  
  dim = atoi(argv[1]);
  total_processes = atoi(argv[2]);
  createMatrix(dim);
  
  printMatrix(dim);
  
  
  destroyMatrix(dim);
  return 0;
}
