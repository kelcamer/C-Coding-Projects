#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct mys{
    int data;
    struct mys *next;
    struct mys *prev;

}myL;

myL *front, *rear, *temp;
int totalnodes = 0;
  int n = 1;
void printlist(myL *first);
void printbackwards(myL *last);
myL* newnd(void);
myL* push(myL *first, myL *last);
myL* pop(myL *first, myL *last);
void main(){
    // VARIABLES
    front = temp = rear = NULL;
    totalnodes = 0;
    int choice = 1;



    while(choice!=0){
        front = push(front, rear);
        printlist(front);

    printf("Push = 1\nPop = 2\nExit = 0\n");
        scanf("%d",&choice);

        if(choice == 1){
        front = push(front, rear);
        printlist(front);

        printf("Continue Push = 1\nPop = 2\nExit = 0\n");
        scanf("%d",&choice);
        }
        else if(choice == 2){
        if(front != NULL){
        rear = pop(front, rear);
        printf("Push = 1\nContinue Pop = 2\nExit = 0\n");
        scanf("%d",&choice);
        }
        else{
            printf("List is NULL, cannot pop anymore.\n");
            printf("Push = 1\nExit = 0\n");
        }
        }
        else{
                //  printbackwards(rear);
            break;
        }
    }


}
void printlist(myL *first){
    myL *temp2 = NULL;
    temp2 = first;
 while(temp2 != NULL){
        printf("%d->", (temp2->data));
        temp2 = temp2->next;
    }
printf("NULL\n");
printf("There are %d nodes in your list.\n", totalnodes);
}
myL* newnd(void){
return (myL *)malloc(sizeof(myL));
}
myL* push(myL *first, myL *last){
    temp = last;
n = 1;
    while(n!=0){
    last = newnd();
    printf("Please enter a number:\n");
    scanf("%d", &(last->data));
        if(first == NULL){
            first = temp = last;
            totalnodes++;
        }
        else if(first != NULL){
            temp->next = last;
            last->prev = temp;
            temp = last;
            totalnodes++;

        }

        fflush(stdin);
    printf("Continue push = 1\nExit = 0\n");
   scanf("%d", &n);
    first->prev = NULL;
    last->next = NULL;


    }
    rear = last;
   return first;
}
myL* pop(myL *first, myL *last){
// get rid of last node every time
n = 1;
while(n!=0){
          totalnodes--;
    if(last!=first){
temp = last->prev;
free(last);
last = temp;
last->next = NULL;
printlist(first);
    printf("Continue pop = 1\nExit = 0\n");
   scanf("%d", &n);

  }
  else{
    free(first);
    free(last);
    printf("List is NULL.\n");
    break;
  }

}
return last;
}
void printbackwards(myL *last){
    myL *temp2 = NULL;
    temp2 = last;
 while(temp2 != NULL){
        printf("%d->", (temp2->data));
        temp2 = temp2->prev;
    }
printf("NULL\n");
printf("There are %d nodes in your list.\n", totalnodes);


}
