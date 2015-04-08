#include <stdio.h>
#include <stdlib.h>

void swap(char *word, int i, int j){
    char *temp = word[i];
    word[i] = word[j];
    word[j] = temp;

}

void permutate(char *word, int k, char *output){
    FILE *out;
    if(out != NULL){
        out = fopen(output, "a");
    }
    char *orig = word;
    int j;
  //  int num_letters = sizeof(word) / sizeof(char);


    for(j = k; j < strlen(word); j++){
        swap(word, k, j);
    //    permutate(word, k+1, output);
    for(j = k; j < strlen(word); j++){
        swap(word, k+1, j);
        swap(word, k+1, j);

        if(k == strlen(word)){
        printf("%s\n", word);

        }   }
        swap(word, j, k);


    }
    }


void getData(char *filename){
    FILE *input = fopen(filename, "r");
    char data[101];
    char newline = '/n';
    char *word = NULL;
    if(input == NULL){
        printf("Error, file cannot be opened!");
        exit(1);
    }
    else{
         while ((fgets(data, 100, input)) != NULL){
            word = strtok(data, "\n");
            printf("Word %s is being permutated.\n", word);
            permutate(word, 0, "AssignmentThreeOutput.txt");


         }



    }

}

void main(void){
    char test[] = "CAT";
    getData("AssignmentThreeInput.txt");
   // permutate(test, 0);

}

