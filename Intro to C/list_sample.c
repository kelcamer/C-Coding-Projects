// Kelsey Cameron
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main(){
	
	struct node{
		// creates a structure named Node in main function
		int num;
		// number variable inside struct node
		struct node *ptr;
		// pointer inside this structure
		
		
	};
	typedef struct node NODE;
	// tells the computer that if I type NODE I want to define a brand new node structure (above)
	NODE *head, *first, *temp;
	// adds three pointers to structure;
	temp = 0;
	// initializes the pointers
	int count = 0;
	int choice = 1;
	temp = head;
	scanf("%d", &head->num);
	first = 0;
	// the first box / node / part of structure should be set equal to a pointer inside of the structure and allocate memory based on the pointers size
	head = (NODE *)(malloc(sizeof(NODE)));
		//printf("%d=>", &head->num);
printf("%d=>", &head->num);
}
