// Kelsey Cameron
// My attempt at a linked list
#include <stdio.h>
#include <stdlib.h>

struct my_structure{
	int num;
	struct my_structure *next;
	
};
//typedef struct my_structure NODE;

int main(){
	int ipt = 1;
	struct my_structure node1, node2, node3;

	
	while(ipt != 0){
		
			
      //  node1  = (NODE *)malloc(sizeof(NODE));
        // sets the node head equal to a new node inside structure
        printf("Enter the data item\n");
        // prints
        scanf("%d", &node1->num);
        // scans in the value of number stored inside the node head inside structure
        // if first is empty

	node1.next = &node2;
	node2.next = &node3;
	printf("%d", node2.num);
	
		return 0;
	}
	
	
	
	
	
	
}
