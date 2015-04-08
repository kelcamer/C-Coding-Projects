/*
Kelsey Cameron

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main(){
int test = 0;
int state = 2;
int sqr = 0;
printf("Please enter a number.\n");
scanf("%d", &test);
// 3, 5, 7, 11, 13, 17, 23, 29, 31,

sqr = sqrt(test);
printf("Square Root: %d\n", sqr);
if(test%2 != 0){

    int num_tested = 0;
    for(num_tested = 3; num_tested < sqr+1; num_tested++){




    }
        /*
    // We can eliminate any even number to start with.  Thus, 2, 4, 6, 8, and 10 cannot be factors.
    if((test%3 != 0) || (test == 3)){
                printf("3 is a factor.");
        if((test%5 != 0) || (test == 5)){
                printf("5 is a factor.");                if((test%7 != 0)  || (test == 7)){                    state = 1;

                }
                else{
                        state = 2;
                        printf("7 is a factor.");
                }
        }
    }

*/
}
else{
        printf("2 is a factor.");
        state = 2;
}

if(state == 1){
    printf("Number is prime!");

}
else if(state == 2){
    printf("Number is not prime!");
}

}
