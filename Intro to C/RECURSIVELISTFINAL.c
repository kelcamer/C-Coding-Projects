#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct mys{
        struct mys *next;
        int data;
        struct mys *prev;
};
typedef struct mys list;

    list *front, *rear, *temp = NULL;
    int count = 0;

list* newnd(void){
return (list *)malloc(sizeof(list));}

list* insert(list *first, list *last){

    if(first == NULL){
    first = newnd();
    printf("Please enter a number:\n");
    scanf("%d", &first->data);
    //first = temp;
    temp = first;
    temp->next = NULL;

    //return temp;
    return first;
    }
    else if(first != NULL){
    printf("Temp Data: %d\n", temp->data);

    first->next = insert(first->next, last);
    (*(*first).next).prev = first;

    }
    rear = temp;
    rear->next = NULL;
    first->prev = NULL;
    free(temp);
    fflush(stdin);
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
void printlistback(list *last){
    if(last == NULL) return;

    printf("%d->", last->data);
    printlistback(last->prev);

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
            printf("\n");
            printlistback(rear);
            printf("NULL\n");            printf("There are %d nodes in this list.\n", count);    }
