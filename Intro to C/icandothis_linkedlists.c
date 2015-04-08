#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// printed backwards
void main(){
	struct my_node{
	int data;
	struct my_node *next_pointer;
	struct my_node *prev;
};
typedef struct my_node SHORTCUT;
	SHORTCUT *head, *firstforevs, *temp = 0;
	int count = 0;
	firstforevs = 0;
	int ipt = 1;
	while(ipt){
		head = (SHORTCUT *)malloc(sizeof(SHORTCUT));
		printf("Please enter a number.\n");
		scanf("%d", &head->data);
		if(firstforevs != 0){
			temp->next_pointer = head;
			head->prev = temp; 
			temp = head;
		}
		else if(firstforevs == 0){
			firstforevs = temp = head;
		}
		fflush(stdin);
		printf("Do you want to continue? Type 1 for yes or 0 for no.\n");
		scanf("%d", &ipt);
		
	}
	firstforevs->prev = 0;
	temp->next_pointer = 0;
	head->next_pointer = 0;
	temp = firstforevs;
	 printf("\n status of the linked list is\n");
    while (head != 0)
    {
        printf("%d=>", head->data);
        count++;
        head = head -> prev;
    }
    printf("NULL\n");
    printf("No. of nodes in the list = %d\n", count);
}

