/*
Kelsey Cameron
Testing the Stat library we created: Part B of Assignment 2 - Computer Analysis with John Edison
2/28/15 - 3/2/15
*/

#include <stdio.h>
#include <stdlib.h>
// imports my library
#include "statlib.c"


void main(void){
        // creates variables
        double mean_v, var, sd = 0.0;
        double array[] = {30.0, 90.0, 100.0, 84.0, 72.0, 40.0, 34.0, 91.0, 80.0, 62.0};
        int numofnum = 10;

        // the array print function prints the array, so it can be used after the sort to print sorted, or before to unsort
        printf("The unsorted array is:\n{");
        print_unsort(numofnum, array);
        printf("}\n");
        // gets mean of array
        mean_v = mean(numofnum, array);
        // gets variance of array
        var = variance(10, array);
        // gets Standard deviation of array
        sd = stdDev(numofnum, array);
        // sorts array
        sort(numofnum, array);
        // gets min, max, and median
        double min = minValue(numofnum, array);
        double max = maxValue(numofnum, array);
        double med = median(numofnum, array);
        // prints
        printf("The mean is: %0.2lf\n", mean_v);
        printf("The population variance is: %0.2lf\n", var);        printf("The population standard deviation is: %0.2lf\n", sd);
        printf("The sorted array is:\n{");
        print_unsort(numofnum, array);
        printf("}\n");
        printf("The minimum value is: %0.2lf\n", min);
        printf("The maximum value is: %0.2lf\n", max);
        printf("The median is: %0.2lf", med);
}
// a Function that just prints the array
void print_unsort(int totnum, double data[]){
    int x = 0;
    for(x = 0; x < totnum; x++){
            if(x!= 0){
                printf(" ,");
            }
        printf("%0.2lf", data[x]);
    }

}

