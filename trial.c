#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

int main(){
    struct mys{
    int data;
    struct mys* next;

    };


    typedef list struct mys*;

    list front, rear, temp = 0;
    int choice = 1;

    while(choice){
        rear = (list *)malloc(sizeof(list));
        printf("Please enter a number.\n");
			// scanning isn't working!!!
			scanf("%d", &rear->data);
			if(front == 0){
                front = temp = rear;
			}
			else if(front != 0){
                rear = temp->next;
                rear = temp;
			}



    }
}
