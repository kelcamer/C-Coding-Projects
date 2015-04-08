#include <stdio.h>
#include <stdlib.h>

struct mys{
    int data;
    struct mys *left;
    struct mys *right;


};
typedef struct mys list;

list* newnd(void){
    list *temp = (list *)malloc(sizeof(list));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = 0;
    printf("Please enter a data value.\n");
    scanf("%d", &temp->data);
//    printf("%d", temp->data);
    return temp;

}
// You must pass in a new node for current
list* create(list *root, list *cur){
        if(root == NULL){
            root = cur;
            return root;
        }
        else{
            if(cur->data > root->data){
                cur = create(root->right, cur);
                printf("Right\n");
            }
            else if(cur->data < root->data){
                cur = create(root->left, cur);
                printf("Left\n");

            }
            }
    return root;
}

void printout(list *node) {
   if((node->left) != NULL){
    printout(node->left);
   }
   printf("%d\n",node->data);
if((node->right) != NULL){
    printout(node->right);
   }
}

void main(void){
    list *tree = NULL;
    list *current = NULL;
    int x = 0;

    for(x = 1; x < 5; x++){
    current = newnd();
    tree = create(tree, current);
    }
    printout(tree);

}
