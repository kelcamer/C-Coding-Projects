#include <stdio.h>
#include <stdlib.h>

int permutate(int start, int end){
    int i = start;
    while(i < end){
    int tot = (start * permutate((start+1), end));
    i++;
    return tot;

    }
}

void main(void){
    int st, ed = 0;
    printf("Enter starting value:");
    scanf("%d", &st);
    printf("Enter ending value:");
    scanf("%d", &ed);
   int total = permutate(st, ed);
    printf("Total: %d", total);

}
