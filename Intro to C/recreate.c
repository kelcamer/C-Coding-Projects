#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct mystruct{
    struct mystruct* next;
    //struct mystruct* prev;
    int data;
};
typedef struct mystruct* list;
int total_nodes = 0;
list front, rear, temp;
list dequeue(list first, list last);
list enqueue(list first, list last);
list pop(list last);
list new_node(list temp2);
void printlist(list first);
void main(){
    int choice = 1;
    //int count = 0;
    int state = 0;
    front = 0;
    //rear = 0;
    temp = 0;
    int p = 4;
    while(choice){
    rear = new_node(rear);
    printf("Please enter a number.\n");
    scanf("%d", &rear->data);
    if((front == 0)){
        front = temp = rear;
    }
    else if(front != 0){
        temp->next = rear;
      //  rear->prev = temp;
        temp = rear;
        total_nodes++;
    }
    fflush(stdin);


    printf("1 = Continue\n0=Exit\n");
    scanf("%d", &choice);
    }

    //    front->prev = 0;
    rear->next = 0;
   printlist(front);

    printf("Would you like to begin a Queue (1) or a Stack? (0)\n");
    scanf("%d", &state);
    if(state == 1){




    printf("Begin Enqueue = 1\n Begin Dequeue = 0\n");
    scanf("%d", &choice);
    if(choice == 1){

        int num2 = 0;
        while(choice){
      //  printf("Please enter a number.\n");
       // scanf("%d", &num2);
        rear = enqueue(front, rear);
        printlist(front);
        printf("Continue enqueue = 1\nExit = 0\nDequeue = 2\n");
        scanf("%d", &choice);
        if(choice == 2){
            break;
        }
        /*
        Question:   When data is printed out of each node, is that data still accessible?
        */
        }
    }
    else if(choice == 0){
            if(front!=0){
       front = dequeue(front, rear);
        printlist(front);
}
    }
    if(choice == 2){
         front = dequeue(front, rear);
        printlist(front);
    }
 }
    else if(state == 0){
    // stack functions option

        printf("Would you like to push (1) or pop? (0)\n");
        scanf("%d", &p);
        if(p == 1){
            rear = enqueue(front, rear);
            printlist(front);
        }
        else if(p == 0){
            // delete last node with pop
        }

    }
    else{
    printf("Would you like to begin a Queue or a Stack?\n");
    scanf("%d", &state);
    }
}
void printlist(list first){
list temp = new_node(temp);
temp = first;
int count = 0;
 while(temp != 0){
            count++;
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("There are %d nodes in this list.\n", count);

}
list enqueue(list first, list last){
    int n = 1;
    int number = -99999;
    while(n!=0){
    list temp = new_node(temp);

    if(first == 0){
        first = temp;
    }
    else{
    printf("Please enter a number.\n");
    scanf("%d", &number);
    temp->data = number;
    last->next = temp;
    last = temp;
    last->next = 0;
    total_nodes++;
    }
//////
    printf("Continue enqueue = 1\nExit = 0\n");
   scanf("%d", &n);
    }
    return last;

}

list dequeue(list first, list last){
    // take away the first
    // first in, first out
    int x = 0;
    int n = 1;
    while(n != 0 && x < total_nodes+1){
    printf("Number %d-Dequeuing:  %d\n", n, first->data);
    list temp = first;
    if(temp == 0){
       printf("List is NULL\n");
    }
    else if((first == 0) && (last == 0)){
        printf("I will dequeue your only node.\n");
        front = rear = 0;
    }
    else{
    first = first->next;

    }

    free(temp);
    last->next = 0;
   // first = temp;
   printf("Continue dequeuing = 1\nExit = 0\n");
   scanf("%d", &n);
    x++;
    }
    return first;

}
list new_node(list temp2){
    temp2 = (list *)malloc(sizeof(list));
    if(temp2 == 0){
        printf("Insufficient Memory to create a new node.\n");

    }
    return temp2;
}
list pop(list last){
// I want to add an element to the end of this list.

    list temp = new_node(temp);
    temp = last;


}



/*
Notes on Stacks:
1.   LAST IN FIRST out.



*/
