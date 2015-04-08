#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

/*
Provide the user a menu of the following options:
1. Insert
2. Display
3. Delete by ID
4. Delete by Name
5. Exit

*/
// Since I am not sure how many comments you want, Mrs. Whiting, I decided to put as many as I thought were needed.
struct node{
    char name[50];
    int  id;
    struct node *next;
    struct node *prev;
};
typedef struct node list;

// defines public variables
list *front, *rear, *temp = NULL;
int count = 0;

// a function that returns a new node
list* newnd(){
return (list *)malloc(sizeof(list));
}


void display_list(list *first, list *last){
    if(first == NULL){
        printf("List is empty.\n");
    }
    else{

        printf("Name: %s\nId: %d\n\n", first->name, first->id);
        if(first->next != NULL){
        // uses recursion to easily display the list
        display_list(first->next, last);
        }
        else{
            printf("End of List\n\n");
        }
    }
}
list* delete_name(list *first, list *last, char *name){

    list *temp2, *temp3, *temp6 = NULL;
    if(first == NULL){
        printf("Name was not found.\n\n");
    }
    else{
            temp2 = first->next;
            temp3 = first->prev;

            if(strcmp(name, first->name) == 0){
                printf("Name was found, now deleting.\n\n");
            if(temp2 == NULL){
        // last node
                temp6 = temp3->next;
                temp3->next = NULL;
                free(temp6);
                }
                else if(temp3 == NULL){
        // first node
                free(first);
                return temp2;
                }
                else{
            free(first);
            temp3->next = temp2;
            temp2->prev = temp3;
            temp3 = temp2;
            }
        }
        else{
                // keep searching through the list until end
            delete_name(first->next, last, name);
        }

    }
    return first;

}

list* delete_id(list *first, list *last, int id){
        list *temp4, *temp5, *temp6 = NULL;
    if(first == NULL){
        printf("NULL\n\n");
            printf("Id was not found.\n\n");
    }
    else{
        temp4 = first->next;
        temp5 = first->prev;

        if(id == first->id){
            printf("Id was found, now deleting.\n\n");
                if(temp4 == NULL){
            // this means the node is the last node
                temp6 = temp5->next;
                temp5->next = NULL;
                free(temp6);
                }
                else if(temp5 == NULL){
            // this means the node is the first node
                free(first);
                return temp4;
                }
                else{

                    free(first);
                    temp5->next = temp4;
                    temp4->prev = temp5;
                    temp5 = temp4;
                    }
        }
        else{
        delete_id(first->next, last, id);
        }
        return first;
    }

}
list* insert_nd(list *first, list *last){
    char name[100];
    char id2[8];

    if(first == NULL){
        printf("List is empty!\n");

    }
    else if(first != NULL){
        temp = newnd();
    // SCAN IN DATA
        printf("Please enter the full name of the person, with a comma at the end.\n");
       fgets(name, sizeof(name), stdin);
        strtok(name, "\n");
        strcpy(&temp->name, name);
      printf("Please enter the id of the person.\n");
        fgets(id2, sizeof(id2), stdin);        strtok(id2, "\n");
        temp->id = atoi(id2);
        last->next = temp;
        temp->prev = last;
        last = temp;

    }
            last->next = NULL;
            first->prev = NULL;
    fflush(stdin);
    return first;

}
list* create_list(list *first, list *last){
    char data[51];
    char *name;
    char *id;
    const char comma[2] = ",";

// Read from a file
    FILE *io;
    io = fopen("AssignmentOneInput.txt", "r");
    if(io == NULL){
        printf("Can't open file.\n");
        exit(1);
    }

// Use fgets even though I really really really don't like input buffers
while ((fgets(data, 50, io)) != NULL){
    name = strtok(data, comma);
    id = strtok(NULL, comma);

        last = newnd();
        strcpy(&last->name, name);
        last->id = atoi(id);
    if(first == NULL){
            // set everything to the first node
        first = temp = last;
        }
    else if(first != NULL){

        // connect temp to last
        temp->next = last;
        // connect last to temp
        last->prev = temp;
        // set the temp now as the new last node, so you can continue the list
        temp = last;

        // make node before first null
        first->prev = NULL;
        // make node after last null
        last->next = NULL;

        // set public variable as last, I doubt I'll need it but it can be handy
        rear = last;

    }

    }
    fflush(stdin);
    return first;
}
void main(void){
    // defines variables
    int choice = 0;
    int choice2 = 1;
    char name[100];
    char id[8];
    char *name2 = &name;
    char *id_ref = &id;
    // defines the most hated input buffer ugh
    char buffer[50];
    int final_id = -9999999;


  if(front == NULL){
        front = create_list(front, rear);
        }
 //       else{
                // conditional statement within a loop
 while(choice != 5){
        // fixing C's stupid fgets error because of the input buffer
        int c = 0;
        printf("1. Insert\n2. Display\n3. Delete by ID\n4. Delete by Name\n5. Exit\n");
        fgets(buffer, 50, stdin);
        strtok(buffer, "\n");
        // atoi converts a string array to an int
        choice = atoi(buffer);
 // the conditional statements begin!
    if(choice == 1){
        front = insert_nd(front, rear);
    }
    else if(choice == 2){
        display_list(front, rear);
    }
    else if(choice == 3){
        printf("Please enter the ID you would like to delete.\n\n");
        fgets(id, sizeof(id), stdin);        strtok(id, "\n");
        final_id = atoi(id);
        front = delete_id(front, rear, final_id);
        while((c = getchar()) != '\n' && c != EOF);
    }
    else if(choice == 4){
        printf("Please enter the name you would like to delete.\n\n");
        fgets(name, sizeof(name), stdin);
        strtok(name, "\n");
        front = delete_name(front, rear, &name);
    }
    else if((choice == 5)){
        printf("Exit\n");
         break;
    }
    else{
        printf("Invalid choice.\n\n");
        printf("1. Insert\n2. Display\n3. Delete by ID\n4. Delete by Name\n5. Exit\n");
        fgets (buffer, 50, stdin);
        strtok(buffer, "\n");

    }
    }
}
//}


/*
/////////////////////////////////////////////////////
If you are a teacher, please ignore the following comments.
They are simply a reference for me to remember how to use
an input buffer in C.



dataLine could be a char array
while ((fgets(dataLine, LENGTH, filePointer)) != NULL){
    name = strtok(dataLine, comma);
    id = strtok(dataLine, comma);

}

int intId = atoi(intId);
/////////////////////////////////////////////////////
*/
