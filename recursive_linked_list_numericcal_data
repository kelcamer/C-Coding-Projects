#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct mys{
    struct mys *next;
    struct mys *prev;
    int data;


};
typedef struct mys list;

list* newnd(void){
return (list *)malloc(sizeof(list));
}

list *front, *rear, *temp = NULL;
int count = 0;
list* insert(list *first, list *last){
    if(first == NULL){
    first = newnd();
    printf("Please enter a number:\n");
    scanf("%d", &first->data);
    temp = first;
    first->next = NULL;
    return first;
    }
    else if(first != NULL){
    first->next = insert(first->next, last);


    }
    rear = temp;
    rear->next = NULL;
    first->prev = NULL;
   // free(temp);
    fflush(stdin);

return first;
}

void printlist(list *temp){

        if(temp==NULL){
            return;
        }
        else{
            printf("%d->", temp->data);
            printlist(temp->next);
        }
}

void main(void){
     int loop = 0;
    printf("How many numbers do you want?\n");
    scanf("%d", &loop);
    for(count = 0; count < loop; count++){
    front = insert(front, rear);

    }
            printlist(front);
            printf("NULL\n");


}
