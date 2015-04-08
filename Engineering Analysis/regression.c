/*
Kelsey Cameron
Regression Part C of Assignment 2 - Computer Analysis with John Edison
2/28/15 - 3/2/15
*/

#include <stdio.h>
#include <stdlib.h>
#include "statlib.c"

void main(void){
    // Creates Variables
    double input[2][10] = {{0, 5, 10, 15, 20, 25, 30, 35, 40, 45}, {0, 13, 22, 37, 54, 62, 64, 100, 112, 126}};
    double ydif, tdif, tdif2 = 0.0;
    double b, v = 0.0;
    double total_top = 0.0;
    int n = 10;
    int x = 0;
    int j = 0;

    // Calculates mean
    double t_m = mean(10, input[0]);
    double y_m = mean(10, input[1]);


    for(x = 0; x < n; x++){
        // Gets first dimension difference of t
        tdif = input[0][x] - t_m;
        // Gets first dimension difference of y
        ydif  = input[1][x] - y_m;
        // Squares total numerator
        total_top += tdif * ydif;
        // gets denominator
        tdif2 += (tdif * tdif);
    }

    // divides to get V
    v = (total_top / tdif2);
    // prints
    printf("V = %0.2lf\n", v);
    // Uses given algorithm of a line (linear) to get B
    b = y_m - (v * t_m);
    // prints
    printf("B = %0.2lf", b);

}
