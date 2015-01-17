
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct mylist{
    struct mylist *next;
    int data;


};
typedef struct mylist list;
list *front, *rear = 0;
        int num = 0;
list* newnode(void){
return (list *)malloc(sizeof(list));
}

list* insert(list *first, list *last, int loop){
        list *temp = 0;
        list *nxtnd = 0;
        int count = 0;
        for(count = 0; count < loop; count++){
        last = newnode();
        printf("Please enter a number.\n");
        scanf("%d", &num);
        last->data = num;
        if(first == 0){
            first = temp = last;
        count++;
        }
        else if(first != 0){
            nxtnd = temp->next;
            temp->next = insert(first, last, loop);
            printf("SECOND");
        }
        fflush(stdin);



        last->next = 0;
}
}
void main(void){
    int loop = 0;
    printf("Repeat how many times?\n");
    scanf("%d", &loop);
    insert(front, rear, loop);



}
