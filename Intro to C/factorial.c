#include <stdio.h>
#include <stdlib.h>

    int ipt = 0;
 int choice = 1;
int getFact(int num);
void main(){

    while(choice != 0){
    printf("Please enter a number to get the factorial of.\n");
    scanf("%d", &ipt);
    int total =  getFact(ipt);
    printf("Result: %d\n", total);
    printf("Continue = 1\nExit = 0\n");
    scanf("%d", &choice);
    }
}
int getFact(int num){
int temp = 0;
if(num>1){
    return num * getFact(num-1);
}
else if(num == 1){
    return 1;
}
else if(num == 0){
    return 1;
}
else{
    while(num <1){
    printf("Invalid for a factorial.\nPlease enter a different number to get the factorial of.\n");
    scanf("%d", &num);
    }
    return(num * getFact(num-1));

}

}
