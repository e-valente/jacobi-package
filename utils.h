#ifndef _UTILS_H
#define _UTILS_H
#endif

#define LEFT 1.0
#define RIGHT 1.0
#define TOP 1.0
#define BOTTOM 1.0
#define EPSILON 0.1
#define MIDDLE 0.0
#define MAXITERS 10000


double **matrix;
double **newmatrix;
double left, right, top, bottom, middle, epsilon;
int dimension, total_processes;

void createMatrix( );
void destroyMatrix( );
void handleInput(int, char**);
void printMatrix( );
double dabs(double);


