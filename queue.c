/*
						Queue


	Queue is a specialized data storage structure (Abstract data type).
	Unlike, arrays access of elements in a Queue is restricted. 
	It has two main operations enqueue and dequeue. 
	Insertion in a queue is done using enqueue function
	and removal from a queue is done using dequeue function.
	An item can be inserted at the end (‘rear’) of the queue
	and removed from the front (‘front’) of the queue. It is 
	therefore, also called First-In-First-Out (FIFO) list. Queue
	has five properties - capacity stands for the maximum number 
	of elements Queue can hold, size stands for the current size 
	of the Queue, elements is the array of elements, front is the 
	index of first element (the index at which we remove the element)
	and rear is the index of last element (the index at which we 
	insert the element).
*/


#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
 
 // My struct contains a number and next pointer
struct my_struct
{
  int num;
  struct my_struct* next;
};
 
 // my list contains a head and a tail
struct my_list
{
  struct my_struct* head;
  struct my_struct* tail;
};
 
 // defines type of functions, basically it returns a bunch of structs
struct my_list* list_add_element( struct my_list*, const int);
struct my_list* list_remove_element( struct my_list*);
 
 
struct my_list* list_new(void);
struct my_list* list_free( struct my_list* );
 
void list_print( const struct my_list* );
void list_print_element(const struct my_struct* );
 
 
int main(void)
{
	// creates a new list, nullifies
  struct my_list*  mt = NULL;
 // creates an empty head and tail in list
  mt = list_new();
  list_add_element(mt, 1);
  // add 1 to list
  list_add_element(mt, 2);
  list_add_element(mt, 3);
  list_add_element(mt, 4); 
  // add various numbers to list
   
  list_print(mt);
 
  list_remove_element(mt);
  list_print(mt);
 
  list_free(mt);   /* always remember to free() the malloc()ed memory */
  free(mt);        /* free() if list is kept separate from free()ing the structure, I think its a good design */
  mt = NULL;      /* after free() always set that pointer to NULL, C will run havon on you if you try to use a dangling pointer */
 
  list_print(mt);
 
  return 0;
}
 
 
 
/* Will always return the pointer to my_list */
struct my_list* list_add_element(struct my_list* s, const int i)
{
	// takes in an empty list, and a constant
	// why is there a constant?
  struct my_struct* p = malloc( 1 * sizeof(*p) );
  // creates an empty list
 
  if( NULL == p )
    {
      fprintf(stderr, "IN %s, %s: malloc() failed\n", __FILE__, "list_add");
      return s; 
    }
 // transfers the data into this new list
  p->num = i;
  p->next = NULL;
 // sets next to null
 
  if( NULL == s )
    {
      printf("Queue not initialized\n");
      free(p);
      return s;
    }
  else if( NULL == s->head && NULL == s->tail )
    {
      /* printf("Empty list, adding p->num: %d\n\n", p->num);  */
      s->head = s->tail = p;
      return s;
      // if your creation function failed
    }
  else if( NULL == s->head || NULL == s->tail )
    {
      fprintf(stderr, "There is something seriously wrong with your assignment of head/tail to the list\n");
      free(p);
      return NULL;
      // if either your head or your tail failed, it releases the data
    }
  else
    {
      /* printf("List not empty, adding element to tail\n"); */
      s->tail->next = p;
      // sets the next space to p
      s->tail = p;
      // not sure
    }
 
  return s;
}
 
 
/* This is a queue and it is FIFO, so we will always remove the first element */
struct my_list* list_remove_element( struct my_list* s )
{
  struct my_struct* h = NULL;
  struct my_struct* p = NULL;
 
  if( NULL == s )
    {
      printf("List is empty\n");
      return s;
    }
  else if( NULL == s->head && NULL == s->tail )
    {
      printf("Well, List is empty\n");
      return s;
    }
  else if( NULL == s->head || NULL == s->tail )
    {
      printf("There is something seriously wrong with your list\n");
      printf("One of the head/tail is empty while other is not \n");
      return s;
    }
 // takes the head in s (first number) and stores it into an empty struct called h
  h = s->head;
  // takes the number after head in h (second number) and stores it inside empty struct called p
  p = h->next;
  // deletes first number
  free(h);
  // sets the number inside p (the second number from h) and sets it as the new head
  s->head = p;
  if( NULL == s->head )  s->tail = s->head;   /* The element tail was pointing to is free(), so we need an update */
 
  return s;
}
   
 
/* ---------------------- small helper fucntions ---------------------------------- */
struct my_list* list_free( struct my_list* s )
{
  while( s->head )
    {
      list_remove_element(s);
    }
 
  return s;
}
 
struct my_list* list_new(void)
{
	// creates a new list
  struct my_list* p = malloc( 1 * sizeof(*p));
 // if p = 0, then malloc didn't work
  if( NULL == p )
    {
      fprintf(stderr, "LINE: %d, malloc() failed\n", __LINE__);
    }
 
  p->head = p->tail = NULL;
  // sets the head and the tail to null
   
  return p;
  // so all this function seriously does it create a list, nullifies head and tail, and 
  // verifies that malloc works
}
 
 
void list_print( const struct my_list* ps )
{
  struct my_struct* p = NULL;
 
  if( ps )
    {
      for( p = ps->head; p; p = p->next )
    {
      list_print_element(p);
    }
    }
 
  printf("------------------\n");
}
 
 
void list_print_element(const struct my_struct* p )
{
  if( p ) 
    {
      printf("Num = %d\n", p->num);
    }
  else
    {
      printf("Can not print NULL struct \n");
    }
}
