#include <stdio.h>
#include <stdlib.h>

void main(void){
    int number;
    int count = 0;
    int len = 0;
    // we want length to be between 3 and 9
    srand(time(NULL));

    for(count = 0; count < 1000; count++){
    len = (rand()% 7)+3;
    for(count = 0; count < len; count++){
// 97 - 122
    number = (rand() % 26) + 'a';
    printf("%c", number);

    }
    printf("\n");
    }



}
