#ifndef _UTILS_H
#define _UTILS_H
#endif

#define LEFT 1.0
#define RIGHT 1.0
#define TOP 1.0
#define BOTTOM 1.0
#define EPSILON 1.0
#define MIDDLE 0.0


double **matrix;
double left, right, top, bottom, middle, epsilon;
int dimension, total_processes;

void createMatrix( );
void destroyMatrix( );
void handleInput(int, char**);
void printMatrix( );


