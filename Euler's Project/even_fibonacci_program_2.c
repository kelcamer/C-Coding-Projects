#include <stdio.h>
#include <stdlib.h>
// Kelsey Cameron
// Add all even fibonacci numbers less than 4,000,000
void generate(void){
int num1 = 1;
int num2 = 2;
int num3 = 0;
int count = 0;
int total = 0;
    printf("%d, %d, ", num1, num2);
while(num3 < 4000000){
    // 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
    num3 = num1 + num2; // num3 = 3
    if(num3 < 4000000){
    printf("%d, ", num3);




        if(num3 %2 == 0){
            total+=num3;
        }




    num1 = num2;
    num2 = num3;

}

}

printf("Total: %d", total+2);
// 4613732
}
void main(){
    generate();
}
