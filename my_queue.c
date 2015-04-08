#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct mys{
	int num;
	struct mys* next;
	struct mys* prev;
	struct mys* first;
	struct mys* last;
};
typedef struct mys* mylist;
mylist add( mylist, const int);
mylist lremove( mylist);


mylist newlist(void);
mylist lfree( mylist );

void print( const mylist );
void print_element(const mylist );
void main(){
	printf("OPEN");
	mylist mine;
	add(mine, 1);
	printf("CLOSE");

}
mylist add(mylist list, const int data){
	mylist temp1 = 0;
	//mylist temp2 = 0;
	// creates a null mylist
	temp1 = malloc(sizeof(temp1));
	 if( NULL == temp1 )
    {
      printf("IN %s, %s: malloc() failed\n", __FILE__, "list_add");
      return list;
    }
    // transfers first number into mylist
	temp1->num = data;
	// sets next number equal to null
	temp1->next = NULL;

 if( NULL == list )
    {
      printf("Queue not initialized\n");
      free(temp1);
      return list;
    }
  else if( NULL == list->first && NULL == list->last )
    {
      /* printf("Empty list, adding p->num: %d\n\n", p->num);  */
      list->first = list->last = temp1;
      return list;
      // if your creation function failed
    }
  else if( NULL == list->first || NULL == list->last )
    {
      //fprintf(stderr, "There is something seriously wrong with your assignment of first/last to the list\n");
      free(temp1);
      return NULL;
      // if either your first or your last failed, it releases the data
    }
  else
    {
      /* printf("List not empty, adding element to last\n"); */
      list->last->next = temp1;
      // sets the next space to p
      list->last = temp1;
      // not sure
    }

  return list;




}
