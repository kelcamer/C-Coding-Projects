#include <stdio.h>
#include <stdlib.h>
struct mys{
    char *name;
    int asci_sum;
    struct mys *left;
    struct mys *right;


};
typedef struct mys list;

list* newnd(void){
    return (list *)malloc(sizeof(list));
}
int script(void){
    int useript = 1;

            printf("Continue = 1\n Exit = 0");
            scanf("%d", useript);
return useript;

}
list* create(list *root, list *cur){


    if(root == NULL){
        root = cur;
        printf("Hi");
        return;
       }
   // else if(root!=NULL){
       if(cur->asci_sum < root->asci_sum){
            printf("LEFT");
            create(root->left, cur);

        }
        else if(cur->asci_sum > root->asci_sum){
            printf("RIGHT");
            create(root->right, cur);
//            printf("Continue = 1\n Exit = 0");
  //          scanf("%d", useript);

     //   }
            return root;
    }






}
void print_tree(){


}


int getASCIsum(char *word){
    int total = 0;
    int temp = 0;
    int num_of_letter = strlen(word);
    int count = 0;
    for(count = 0; count < num_of_letter; count++){
        temp = (int)word[count];
        printf("Temp: %d\n", temp);
        total += temp;
        printf("Total: %d\n", total);



    }


    return total;

}


int main(void){
        char *word = "a";
 //       getASCIsum("abc");
        list *root = NULL;
        list *current = NULL;
        current = newnd();
        if(current == NULL){
            printf("Malloc failed.");
        }
        current->left = current->right = NULL;
        printf("Please enter a number.\n");
        scanf("%d", current->asci_sum);
        root = create(root, current);
        printf("Hi2");
        return 0;
}
