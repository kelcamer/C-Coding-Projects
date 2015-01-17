#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
    int weight;
    struct node* left;
    struct node* right;
}
;struct node* NewNode(int data);
struct node* rootnode;
void printlist(struct node* root4);
struct node* insert(int data, struct node* node);
void main(void){

int choice = 1;
int number = 0;
    while(choice){
    printf("Please enter a number:");
    scanf("%d", &number);
    insert(number, rootnode);
    printf("Continue = 1\nExit = 0\n");

    scanf("%d", &choice);
}
printlist(rootnode);
}
struct node* NewNode(int data){
  struct node* node2 = (struct node*)malloc(sizeof(struct node));    // "new" is like "malloc"
  node2->weight = data;
  node2->left = NULL;
  node2->right = NULL;

  return(node2);
}
void printlist(struct node* root4){
   // printf("Printing...\n\n");

    if(root4!=0){
        printf("Node->%d\n", root4->weight);
            if(root4->left != 0){
             printf("Left ");
        printlist(root4->left);

            }
            if(root4->right!=0){
        printf("Right ");
    //printf("Node->%d\n", root4->weight);
        printlist(root4->right);
    }
    }
}
struct node* insert(int data, struct node* node) {
  // 1. If the tree is empty, return a new, single node
  if (node == 0) {
       // printf("CREATE");
    return(NewNode(data));
  }
  else {
    // 2. Otherwise, recur down the tree
    if (data <= node->weight) node->left = insert(node->left, data);
    else node->right = insert(node->right, data);

    return(node); // return the (unchanged) node pointer
  }
}
