#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
    struct node *next;
    struct node *prev;
    int data;


};
typedef struct node list;

list *front, *rear, *temp =  NULL;

list* newnd(void){
return ((list *)malloc(sizeof(list)));}

list* insert(list *first, list *last){
    if(first == NULL){
        first = newnd();
    printf("Please enter a number:\n");
    scanf("%d", &first->data);

    temp = first;
   // temp->next = NULL;
    return first;
  // first->next = NULL;
  //  first->prev = NULL;
    }
    else if(first != NULL){
    printf("TEST");
            first->next = insert(first->next, last);
           // (first->next)->prev = first;

    }
    rear = temp;
    rear->next = NULL;
    first->prev = NULL;
    free(temp);
    fflush(stdin);



return first;
}

void main(void){
    int loop = 0;
    int x = 0;
    printf("How many iterations?\n");
    scanf("%d", &loop);

    for(x = 0; x < loop; x++){
    front = insert(front, rear);
    }
}
