#include<stdlib.h>
#include<stdio.h>
// GOAL:  To learn how this program produces a binary tree
//        and to learn how to recreate it, and find a better
//        way of printing it out.
struct mystruct {
   double val;
   struct mystruct * right, * left;
};

typedef struct mystruct list;

   list *current, *root;
// why does the insert function need to take in a pointer to the tree?
void insert(list **tree, list *item) {
    // What I needed before, was some way to keep track of the current node, AND the root.
   if(!(*tree)) {
        // if the tree is null
      *tree = item;
        // sets the tree equal to the current node
      return;
   }
   if(item->val<(*tree)->val){
        // if the value of the current node is LESS THAN the value of the root, put it to the left
      insert(&(*tree)->left, item);
      printf("LEFT\n");}
   else if(item->val>(*tree)->val){
         // if the value of the current node is GREATER THAN the value of the root, put it to the right        insert(&(*tree)->right, item);
        printf("RIGHT\n");}
}

void printout(list *tree) {
   if(tree->left) printout(tree->left);
   printf("%d\n",tree->val);
   if(tree->right) printout(tree->right);
}
list* newnd(void){
    return (list *)malloc(sizeof(list));
}
void main() {
   int i;

   root = NULL;

   for(i=1;i<=14;i++) {
      current = newnd();
      current->left = current->right = NULL;

      printf("Enter a number please:\n");
      scanf("%d", &current->val);
      insert(&root, current);
   }

   printout(root);
}
