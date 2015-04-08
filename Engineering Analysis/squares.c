#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Begins Main Function, doesn't take in any input.
void main(void){

    // Creates two double variables and sets them to 0.0.
    double count = 0.0;
    double squ = 0.0;


    // prints formatting
    printf("x\tx^2\n");

    // Begins the loop to loop 1 to 10.
for(count = 1; count < 11; count++){

        // squares the number.
        squ = pow(count, 2);
    // prints the count number and it's squared value.
    printf("%0.1lf\t%0.1lf\n", count, squ);
}
}
