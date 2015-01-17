#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct mys{
    struct mys *next;
    int data;


};
typedef struct mys list;

list *front, *rear = NULL;


list* newnd(void){
return (list *)malloc(sizeof(list));
}

void insert(list *first, list *last, int loop){
        list *temp = first;


        list *nxtnd = NULL;
        int count = 0;
        int num = 0;
        printf("Please enter a number:\n");
        scanf("%d", &num);
        if(first == NULL){
        temp = newnd();
        temp->data = num;
        temp->next = NULL;
        last = first = temp;
        count++;
        printf("FIRST->DATA: %d\n", temp->next);
       // return first;
        }
        else{

           // nxtnd = first->next;
           count++;
            if(count < loop){
           insert(temp->next, last, loop);

            }
            else{
                return;
            }
           // return;
        }
        last->next = NULL;



}
/*
list *insert(list *p)
   {
        int n = 0;
        printf("Please enter a number:\n");
        scanf("%d", &n);
      list *temp;
      if(p==NULL)
      {
         p=newnd();
         if(p==NULL)
         {
             printf("Error\n");
             exit(0);
         }
         p-> data = n;
         p-> next = NULL;
      } else{
         p->next = insert(p->next);
      }
      return (p);
   }*/
void Reverse_List(list *pNode){
    if(pNode==NULL)
        return;

    Reverse_List(pNode->next);
    printf("The node is %d\n", pNode->data);
}
/*

void printlist(list *first){
    if(first != NULL){
        printf("%d->", first->data);
        first = first->next;
        //printf("NEXT: %d", first->data);
        }

    if(first->next != NULL){
        printlist(first->next);

    }
    first->next = 0;
    printf("NULL\n");





}*/
void main(void){
    int repeat = 0;
    int count = 0;
    printf("Repeat how many times?\n\n");
    scanf("%d", &repeat);
       // for(count = 0; count < repeat; count++){
      //  front = insert(front);
        insert(front, rear, repeat);        insert(front, rear, repeat);
        //}


        Reverse_List(front);
        printf("DONE\n");}
