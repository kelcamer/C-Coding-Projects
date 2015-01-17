#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct mys{
    struct mys* next;
    struct mys* prev;
    int data;

};
typedef struct mys* list;

list new_node(list tempo);
void print_list(list first);
void print_backwards(list last);

int total_nodes = 0;
list front, rear, temp;

void main(void){
    int choice = 1;
    front = 0;
    temp = 0;
    while(choice){

     rear= new_node(rear);
     printf("Please enter a number:\n");
     scanf("%d", &rear->data);
    if(front == 0){
        front = temp = rear;
        total_nodes++;
    }
    else if(front!=0){
    temp->next = rear;
//    rear->prev = temp;
    temp = rear;
    total_nodes++;
    }

    fflush(stdin);

    printf("1 = Continue\n0 = Exit\n");
    scanf("%d", &choice);
    if(choice == 0){
        break;
    }
    }
    rear->next = 0;
   // temp->next = 0;
    //front->prev = 0;
    print_list(front);
}


list new_node(list temp3){
    temp3= (list *)malloc(sizeof(list));
    if(temp3 == 0){
        printf("Malloc failed, sorry.");
    }

}

void print_list(list first){
    list temp2;
    temp2 = new_node(temp2);

     temp2 = first;
    while(temp2 != 0){
        printf("%d->", temp2->data);
        temp2 = temp2->next;

    }
    printf("NULL");
}

