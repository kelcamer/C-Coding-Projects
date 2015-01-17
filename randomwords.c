#include <stdio.h>
#include <stdlib.h>
void main(void){

int c = 0;


srand(time(NULL));
int len = (rand() % 7) + 3;
for(c = 0; c < 1000; c++){
for(c = 0; c < len; c++){

int numb = (rand() % 26) + 'a';
    printf("%c", numb);
}
printf("\n");
}



}
