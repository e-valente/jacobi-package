/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author emanuel
 */

class Jacobi {
    static double LEFT =  1.0, RIGHT =  1.0, TOP = 1.0, BOTTOM = 1.0, EPSILON = 0.1;
    static double MIDDLE = 0.0;
    static long MAXITERS = 100000;
    static int dimension, total_processes;
    static double[][] matrix, newmatrix;

    public static void handleInput(String[] args) {
        switch (args.length) {
            case 7:
                LEFT = Double.parseDouble(args[2]);
                RIGHT = Double.parseDouble(args[3]);
                TOP = Double.parseDouble(args[4]);
                BOTTOM = Double.parseDouble(args[5]);
                EPSILON = Double.parseDouble(args[6]);
                break;

            case 6:
                LEFT = Double.parseDouble(args[2]);
                RIGHT = Double.parseDouble(args[3]);
                TOP = Double.parseDouble(args[4]);
                BOTTOM = Double.parseDouble(args[5]);
                break;

            case 5:
                LEFT = Double.parseDouble(args[2]);
                RIGHT = Double.parseDouble(args[3]);
                TOP = Double.parseDouble(args[4]);
                break;

            case 4:
                LEFT = Double.parseDouble(args[2]);
                RIGHT = Double.parseDouble(args[3]);
                break;

            case 3:
                LEFT = Double.parseDouble(args[2]);
                break;
        }//switch
  
        dimension = Integer.parseInt(args[0]);
        total_processes = Integer.parseInt(args[1]);
    }
    

    public static void createMatrix() {
        matrix = new double[dimension][dimension];
        newmatrix = new double[dimension][dimension];

        //left, right
        for (int i = 0; i < dimension; i++) {
            //left
            matrix[i][0] = LEFT;
            //right
            matrix[i][dimension - 1] = RIGHT;
            //top
            matrix[0][i] = TOP;
            //bottom
            matrix[dimension - 1][i] = BOTTOM;

            if ((i > 0) && (i < dimension - 1)) {
                for (int j = 1; j < dimension - 1; j++) {
                    matrix[i][j] = MIDDLE;
                }
            }

        }
    }
 
    public static void printMatrix() {

        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                System.out.format("%f ", matrix[i][j]);
            }
            System.out.format("\n");
        }

    }
 
    public static int jacobi_sequential() {
        int i, j, k;
        double maxdiff;

        /**
         * **Jacobi Execution**
         */
        for (k = 0; k < MAXITERS; k++) {
            /*compute new values for all interior points*/
            for (i = 1; i < dimension - 1; i++) {
                for (j = 1; j < dimension - 1; j++) {
                    newmatrix[i][j] = (matrix[i - 1][j] + matrix[i + 1][j]
                            + matrix[i][j - 1] + matrix[i][j + 1]) * 0.25;
                }

            }
            maxdiff = 0.0;
            for (i = 1; i < dimension - 1; i++) {
                for (j = 1; j < dimension - 1; j++) {
                    maxdiff = Math.max(maxdiff, Math.abs(newmatrix[i][j] - matrix[i][j]));
                }
            }

            /*check for termination*/
            if (maxdiff < EPSILON) {
                break;
            }

            /*copy new grid to prepare for new update*/
            for (i = 1; i < dimension - 1; i++) {
                for (j = 1; j < dimension - 1; j++) {
                    matrix[i][j] = newmatrix[i][j];
                }
            }

        }

        return k; /*iters*/

    }
 
    static void printAttributes() {
  
        System.out.format("%-8s = %d x %d\n", "Grid", dimension, dimension);
        System.out.format("%-8s = %d\n", "numProcs", total_processes);
        System.out.format("%-8s = %.4f\n", "left", LEFT);
        System.out.format("%-8s = %.4f\n", "right", RIGHT);
        System.out.format("%-8s = %.4f\n", "top", TOP);
        System.out.format("%-8s = %.4f\n", "bottom", BOTTOM);
        System.out.format("%-8s = %.4f\n", "epsilon", EPSILON);  
        System.out.format("%-8s = %d\n", "MaxIters", MAXITERS);  
        System.out.format("\n");
    }
    
    /*
     *args
     *startTime and endTime must be in nanoseconds
     */
    static void printExecutionTime(long startTime, long endTime) {
        long totalMicroSecs;
        long secs;

        totalMicroSecs = (endTime - startTime) / 1000;
        secs = totalMicroSecs / 1000000;
        totalMicroSecs = (totalMicroSecs % 1000000);

        System.out.format("Execution Time = %d seconds, %d microseconds\n\n",
                secs, totalMicroSecs);
    }
}


