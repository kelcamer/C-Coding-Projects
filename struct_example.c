/*	Kelsey Cameron
	Structure Example in C	*/
	
#include <stdlib.h>
#include <stdio.h>
// First, this sets aside a block of memory to store variables.  It is similar to a class in C++, but only to the extent of variables 
// as far as I know

typedef int write_instead_int;

typedef struct my_structure{
	write_instead_int num;
	// Adds a variable to this memory with int type but so cool, i didn't even write int here xD
	// NOTE:  Typedefs cannot be used to create a new variable and change the data type
	// ie.   unsigned write_instead_int a; is not allowed.
	
	struct node *next;
}shortcut;


int main(){

	shortcut test;
	// uses data type struct, with name st to create a new reference to structure
	shortcut *ptr;
	// Creates a pointer
	test.num = 100895;
	// sets the variable num inside of the structure named test to the value of 110895
	ptr = &test;
	// sets the pointer to the address of the structure, and this is convenient to pass an entire structure into a function
	printf("%d\n", ptr->num);
	// takes an integer value and tells the pointer to point to num and this prints out the value.
	
	
	
	
}
