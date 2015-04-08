#include <stdio.h>
#include <stdlib.h>

struct myl{
    struct myl *next;
    struct myl *prev;
    int data;
    //int count;
};
typedef struct myl list;
/*
4321
2
3
4231

*/


/////////////// GLOBAL VARIABLES ///////////////
        list *front, *rear, *temp, *temp2 = NULL, *temp3 = NULL;
        list *node1, *node2, *node3 = NULL;
        int count = 1;
        int count2 = 1;        int state = 0;



list* newnd(){
return (list *)malloc(sizeof(list));
}

list* getNth(list *first, int posit){
    list *node = first;    if(node == NULL){
        printf("List is empty.\n");

    }
    else{
        if(count == posit){
            printf("COUNT: %d\n", count);
            node = first;
            node->next = first->next;
            node->prev = first->prev;
            printf("Your node from getNth() is: %d\n", node->data);
            return node;
        }
        else{
        count++;
            node = getNth(node->next, posit);
         // printf("Getting node...\n");
        }
        printf("COUNT: %d\n", count);

}
printf("END OF getNth()\n");
}
/*
list* switch_nodes(list *curr, list *first, int position, int position2){
        printf("COUNT: %d\n", count);
      //  curr = first;
    if(first == NULL){
        printf("List is empty.\n");

    }
    else{
      //  printf("NODE YOU ARE AT: %d\n", curr->data);
        if(count == position){

           node1 = &curr;
           node1->next = curr->next;
           node1->prev = curr->prev;
           printf("ORIG Node 1: %d\n", node1->data);


        }
        if(count == position2){

            node2 = &first;
            node2->next = curr->next;
            node2->prev = curr->prev;
            printf("ORIG Node 2: %d\n", node2->data);

        }


        if((node1 != NULL) && (node2 != NULL)){

            //temp2 = node1;
            //temp3 = node2;



            //node2->next = node1->next;
            //node2->prev = node1->prev;
            //node1->prev = temp3->prev;
            //node1->next = temp3-> next;


            //node3 = node1;

        // put data from node2 in node1
            //node1 = node2;

        // put data from node1 in node2
            //node2 = node3;

            printf("FIN Node 1: %d\n", node1->data);            printf("FIN Node 2: %d\n", node2->data);
//            free(node3);
            }
    else{
            count++;
            first->next = curr->next = switch_nodes(curr->next, first, position, position2);
        }


    }

        //    display_list(curr, rear);
    return curr;
}
*/
list* swap(list *first, list *last, int position1, int position2, int count, list *temp1, list *temp2){



    //if(position1 != position2){
        if(first == NULL){
            printf("List is empty.");
            return;
      }

        //else{
            if(count == position1){
                  printf("HI");                if(temp2 == NULL){
                temp1 = newnd();
                temp1->next = first->next;
                temp1->prev = first->prev;
                }
            }
            else if(count == position2){
                if(temp2 == NULL){
                temp2 = newnd();
                temp2->next = first->next;
                temp2->prev = first->prev;

                    }
            }
            else{
    if((temp1->next != NULL) || (temp2->next != NULL)){
        return first;
    }

                first = swap(first, last, position1, position2, count, temp1, temp2);
                return first;
            }

            list *temp3 = temp1;
            temp1 = temp2;
            temp2 = temp3;
            free(temp3);
        //}

    //}
//    else{
    //    printf("You have only one node in your list, so it cannot be swapped.");
      //  return;
  //  }

    count++;
    return first;
}
int user_ipt(void){
        int data2 = 0;
        printf("Please enter a number to be added to your list.\n");
        scanf("%d", &data2);
        return data2;
}
int cont(void){
    int data3 = 0;
    printf("Continue = 1\nExit = 0\n");
    scanf("%d", &data3);
    return data3;

}
list* insert_node(list *first, list *last){


    if(first == NULL){
        first = newnd();
       // count++;

        first->data = user_ipt();
        first->next = NULL;
        rear = first;
    }
    else{
        first->next = insert_node(first->next, last);
        temp = first->next;
        temp->prev = first;
        // (*(*first).next).prev = first;        // I think I can replace the above with lines 39 - 41
    }
        first->prev = NULL;
        fflush(stdin);
    return first;
}
list* delete_nd(list *first, list *last){




}
list* sort_list(list *first, list *last){
    // 3 5 2 7
    list *temp2, *temp3 = NULL;
    if(first->data > first->next->data){
        temp2 = first;
        temp3 = first->next;


    }



return first;
}
list* switch_two(list *first, int p1, int p2){
    printf("Entering function\n");
    int state = 0;
    list *node1, *node2, *node3 = NULL;
    if(first!=NULL){
            if(count2 == p1){
                first = getNth(first, p2);
                first->next = getNth(first, p2+1);
                first->prev = getNth(first, p2-1);
            }
            else if(count2 == p2){
                first = getNth(first, p1);
                first->next = getNth(first, p1+1);
                first->prev = getNth(first, p1-1);
            }
            else{
                count2++;
                first->next = switch_two(first, p1, p2);

            }

    }
    else{
        printf("List is empty.\n");
    }

return first;
}
void display_list(list *first, list *last){
    if(first == NULL){
        printf("List is empty.\n");
    }
    else{

        printf("%d->", first->data);
        if(first->next != NULL){
        // uses recursion to easily display the list
        display_list(first->next, last);
        }
        else{
            printf("End of List\n\n");
        }
    }
}
void main(void){
    // first gets the list
    int choice = 1;
    int pos1, pos2 = 0;
        while(choice ==1){
    //        front->count = count;
            front = insert_node(front, rear);
            choice = cont();
            }


    // displays list
    display_list(front, rear);

    // sorts list


    list *del = NULL;
    list *del2 = NULL;
    printf("Please enter the first position, then press enter, \nthen enter the second.\n");
    scanf("%d", &pos1);
    scanf("%d", &pos2);    front = swap(front,rear, pos1, pos2, 0, del, del2);
        display_list(front, rear);
 //   list *temp8 = NULL;
  //  temp8->data = 7;
  //  front = temp8;
  //  printf("DATA: %d", front->data);


    free(temp);
    printf("\nCompleted Successfully :)\n");
}



/*

Let's say I wanted to switch nodes 2 and 4.
First, I would need to store both of them in temporary variables.
Then, I would need to free both node 2 and node 4.
Then, I would have to insert node 4 where node 2 was.
Then, I would need to insert node 2 where node 4 was.



*/
