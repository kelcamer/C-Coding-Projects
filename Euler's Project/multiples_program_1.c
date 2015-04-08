#include <stdio.h>
#include <stdlib.h>
/*
Kelsey Cameron
If we list all the natural numbers below 10 that are multiples of 3 or 5,
 we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/
void main(void){
    int count = 1;
    int total = 0;
    for(count = 1; count < 1000; count++){

        if(count % 3 == 0){
            total+=count;
        }
        else if(count % 5 == 0){
            total += count;
        }

    }

    printf("Total: %d", total);

}
