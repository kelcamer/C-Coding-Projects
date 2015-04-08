#include "stdio.h"

struct node
{
    int n;
    struct node* link;
};

struct node* node1=NULL;
struct node* node2=NULL;
struct node* node3;

void create();

main()
{
    char c;
    printf("Do you want to create a linked list? ");
    scanf("%c",&c);
    if(c=='y')
        create();
}


void create()
{
    struct node a;
    char ch;
    if(node1==NULL)
    {
        printf("\nEnter the Integer Value: ");
        scanf("%d",&(a.n));
        a.link=NULL;
        node1=&a;
        node2=&a;
        printf("\nTesting1 %d",node2->n);
    }
    else
    {
        printf("\nEnter the Integer Value: ");
        scanf("%d",&(a.n));
        a.link=NULL;
        node1->link=&a;
        node1=node1->link;
        printf("\nTesting2 %d",node1->n);
    }
    printf("\nDo you want to enter more elements in linked list? ");
    scanf("%s",&ch);
    printf("\nTesting2.5 %d",node2->n);  //it gives output 0
    if(ch=='n')
        return;
    else
    {
        printf("\nTesting3 %d",node2->n);
        while(node3!=NULL)
        {
            printf("\nTesting4 %d",node2->n);  // always prints 0
            printf("\n");
            node3=node3->link;
        }
        create();
    }
}
