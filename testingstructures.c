#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct mys{
    struct mys *next;
    char *name;

};
typedef struct mys list;
list *front, *rear, *temp = NULL;
int count = 0;

// Create newnd has a type of list because you are changing the actual node.
list* newnd(void){
return (list *)malloc(sizeof(list));
}
list* insert(list *first, list *last){
    char *n;
if(first == NULL){
    first = newnd();
    printf("Please enter a name.\n");
    scanf("%s", &n);
    strcpy(first->name, n);
    temp = first;
    first->next = NULL;
    return first;
}
else{
   first->next = insert(first->next, last);
}
rear = temp;
rear->next = NULL;
fflush(stdin);
return first;

}
void printlist(list *temp){

        if(temp==NULL){
            return;
        }
        else{
            printf("%s->", temp->name);
            printlist(temp->next);
        }
}

void main(){
     int loop = 0;
    printf("How many numbers do you want?\n");
    scanf("%d", &loop);
    for(count = 0; count < loop; count++){
            printf("Please enter a name.\n");
    front = insert(front, rear);

    }
            printlist(front);
            printf("NULL\n");



}
