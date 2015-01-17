#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct mys{
    struct mys *left, *right;
    int data;
};
typedef struct mys list;
//          VARIABLES
list *root_node, *current_node;


//////////////////////

list* create(void){
    return (list *)malloc(sizeof(list));
}
void printTree(list *root){
    if(root != NULL){
        if(root->left != NULL)
        printTree(root->left);
        printf("%d", root->data);
        if(root->right != NULL)
        printTree(root->right);
    }
}
void insert(list **tree, list *current){
    if(tree == NULL){
        *tree = current;
//        *tree->data = current->data;
        return;
    }
    else{
            if(current->data >  (*tree)->data){
                printf("RIGHT\n");
                insert(&(*tree)->left, current);
            }
            else if(current->data < (*tree)->data){
                printf("LEFT\n");
                insert(&(*tree)->left, current);
            }

    }


}
void main(void){
    int choice = 1;
    while(choice){
            root_node = NULL;
      current_node = create();
      current_node->left = current_node->right = NULL;
            printf("Please enter a number.\n");
            scanf("%d", &current_node->data);
        insert(&root_node, current_node);


              printf("Continue = 1\nExit = 0\n");
        scanf("%d", &choice);
    }

}
