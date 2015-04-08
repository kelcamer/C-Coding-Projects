#include <stdio.h>
#include <stdlib.h>

struct myl
{
    struct myl *next;
    struct myl *prev;
    int data;
    //int count;
};
typedef struct myl list;



list* newnd()
{
    return (list *)malloc(sizeof(list));
}

list* getNth(list *first, int posit, int count)
{
    list *node = first;
    if(node == NULL)
    {
        printf("List is empty.\n");

    }
    else
    {
        if(count == posit)
        {
            printf("COUNT: %d\n", count);
            node = first;
            node->next = first->next;
            node->prev = first->prev;
            printf("Your node from getNth() is: %d\n", node->data);
            return node;
        }
        else
        {
            count++;
            node = getNth(node->next, posit, count);
            // printf("Getting node...\n");
        }
        printf("COUNT: %d\n", count);

    }
    printf("END OF getNth()\n");
}

int user_ipt(void)
{
    int data2 = 0;
    printf("Please enter a number to be added to your list.\n");
    scanf("%d", &data2);
    return data2;
}
int cont(void)
{
    int data3 = 0;
    printf("Continue = 1\nExit = 0\n");
    scanf("%d", &data3);
    return data3;

}
list* insert_node(list *first, list *last)
{


    if(first == NULL)
    {
        first = newnd();
        first->data = user_ipt();
        first->next = NULL;
        first->prev = NULL;

    }
    else
    {

        list *temp = insert_node(first->next, last);
        first->next = temp;
        temp->prev = first;



//    last = temp;
    }
   // printf("LAST: %d", first->prev->data);
   // first->prev = last;
    //last->next = first;
    fflush(stdin);
    return first;
}
list* add_node_at(list *cur, list *first, int pos, int count){
    list *temp3 = newnd();
    first->data = user_ipt();

    if(first == NULL){
        printf("You do not have a linked list.");
        first = temp3;
        first->next = NULL;
        first->prev = NULL;

    }
    else{

        if(count == pos){
            // you want to connect your current node to the new node
            // you want to save the next node, and prev node from your cur node
            list *tem1 = NULL;
            //list *tem2 = NULL;
            tem1 = cur->next;
            //tem2 = cur->prev;
            cur->next = temp3;
            temp3->prev = cur;
            temp3->next = tem1;
            return cur;
        }
        else if(count != pos){
        add_node_at(cur->next, first, pos, count);
        }
    }


    return cur;

}
list* delete_at(list *cur, list *last, int pos, int count)
{
    if(cur == NULL)
    {
        printf("List is null.\n");
        return cur;
    }
    if(cur->next == NULL){
        list *temp3 = cur;
        temp3 = cur->prev;
        free(cur);
        cur = temp3;


    }

    if(pos == count)
    {
        list *temp = cur->prev;
        list *temp2 = cur->next;
     //   if(cur->next != NULL)
       //     printf("Cur-> next -> data: %d\n", cur->next->data);

 //       if(cur->prev != NULL)
   //         printf("Cur-> prev -> data: %d\n", cur->prev->data);

        free(cur);
        cur = temp2;
        cur->prev = temp;
        cur->next = NULL;
        }
    else
    {
        count++;
        list *temp4 = delete_at(cur->next, last, pos, count);
        cur->next = temp4;
        temp4->prev = cur;
        return cur;
    }


}
void display_list(list *first, list *last)
{
    if(first == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {

        printf("%d->", first->data);
        if(first->next != NULL)
        {
            // uses recursion to easily display the list
            display_list(first->next, last);
        }
        else
        {
            printf("End of List\n\n");
        }
    }
}


void main(void)
{
    // first gets the list
    list *front, *rear;
    front = NULL;
    rear = NULL;
    int pos1, pos2 = 0;
    int choice = 1;
    while(choice)
    {
        //        front->count = count;
        front = insert_node(front, rear);
        printf("Continue = 1\nExit = 0\n");
        scanf("%d", &choice);
    }
    rear = front->prev;
    //printf("Rear: %d", rear);
    front = add_node_at(front, front, 2, 0);
    //front = delete_at(front, front->prev, 0, 0);
    // displays list
    display_list(front, rear);


}
