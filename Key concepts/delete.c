#include <stdio.h>
#include <stdlib.h>

struct myl{
    struct myl *next;
    struct myl *prev;
    int data;
   // int count;
};
typedef struct myl list;

void main(void){

    list *first, *node1, *node2, *node3 = NULL;
    first->data = 4;
    first = first->next;
    first->data = 3;
    first = first->next;
    first->data = 2;
    first = first->next;
    first->data = 1;
    first = first->next;



 if((node1 != NULL) && (node2 != NULL)){
            printf("Switching nodes...\n");
            node3 = node1;
            node3->next = node1->next;
            node3->prev = node1->prev;
        // put data from node2 in node1
            node1 = node2;
            node1->next = node2->next;
            node1->prev = node2->prev;
        // put data from node1 in node2
            node2 = node3;
            node2->next = node3->next;
            node2->prev = node3->prev;

            printf("FIN Node 1: %d\n", node1->data);            printf("FIN Node 2: %d\n", node2->data);
            free(node3);

}
