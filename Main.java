/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author emanuel
 */
public class Main {
    
    /**
     *
     * @param args
     */
    public static void main(String[] args) {
        long startTime, endTime;
        
        if(args.length < 2) {
            System.err.println("Usage: java Main <dimension> <number of "
            + "processes> [left, right, top, bottom, EPSILON] \n");
            System.exit(1);
        }
        
        /*Handle input arguments*/
        Jacobi.handleInput(args);
        
        /*Jacobi method*/
        Jacobi.createMatrix();
        startTime = System.nanoTime();
        Jacobi.jacobi_sequential();
        endTime = System.nanoTime();
        
        Jacobi.printMatrix();
        Jacobi.printExecutionTime(startTime, endTime);
    }
}
        
       
   