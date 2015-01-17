#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct mys{
	int num;
	struct mys* next;
};
typedef struct mys* shortcut;
	struct mys* front = 0;
	struct mys* rear = 0;
	struct mys* temp = 0;
// definition of functions
void print_list(struct mys*);
void add_element(struct mys*, int);
void enqueue(int x);
void dequeue(void);
void main(void){
		int choice = 1;
		int count = 0;
		front = 0;
		temp = 0;
		while(choice){
		rear = (struct  mys*)malloc(sizeof(struct mys));


			printf("Please enter a number.\n");
			// scanning isn't working!!!
			scanf("%d", &rear->num);
		//	printf("test");
			if(front == 0){

				front = temp = rear;
			}
			else if(front != 0){
				temp->next = rear;
				temp = rear;
			}



			 fflush(stdin);
        printf("Do you want to continue(Type 0 or 1)?\n");
        scanf("%d", &choice);
		}

		rear->next = 0;
		temp = front;
		while(temp != 0){

            printf("%d->", temp->num);

			count++;
            temp = temp->next;
		}
        enqueue(99999999);
        count++;
			printf("NULL\n");
			printf("There are %d nodes in this linked list.\n", count);

	}





void enqueue(int x){
	// creates a new empty node named temp
	struct mys* temp = malloc(sizeof(struct mys));
	// stores data
	temp->num = x;
	// if both are null, it's the first time doing stuff
	if((front == NULL) && (rear == NULL)){
		// sets front and rear as your new node.
		front = rear = temp;
	}
	else{
		// if there exists a linked list already
		// set temp equal to the next one of rear
		rear->next = temp;
		// change rear to new temp
		rear = temp;

	}

}

void dequeue(void){
	// gets the first element
	struct mys* temp = front;
	// checks if list is empty
	if(front == NULL){
		printf("List is empty");
	}
	// self explanatory
	else if(front == rear){
		printf("Front and rear are the same, so I will dequeue your only node.");
		front = rear = NULL;
	}
	//  sets front to the second node, and frees the old first node named temp
	else{
		front->next = front;
	}
	free(temp);

}


