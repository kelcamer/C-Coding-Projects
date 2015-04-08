// Permutations Program
// Kelsey Cameron
#include <stdio.h>
#include <stdlib.h>

// A function that swaps two characters
void swap(char *word, int i, int j){
    char *temp = word[i];
    // store first char into temp
    word[i] = word[j];
    // set first equal to second
    word[j] = temp;
    // set the second equal to temp

}

void permutate(char *word, int k, FILE *out){

        int j;

        // if you've gone through the entire permutation, print it out
        if(k == strlen(word)){
        fprintf(out, "%s\n", word);

        }
        else{
                // else create a loop for each character in the word
    for(j = k; j < strlen(word); j++){
            // swap the first indices
        swap(word, k, j);
        // permutate the rest of the words
        permutate(word, k+1, out);
        // return the character to it's previous value
        swap(word, j, k);


    }
    }

}
// Opens files and calls permutation program
void getData(char *filename, char *output_name){
    FILE *input = fopen(filename, "r");
    char data[101];
    char newline = '/n';
    char *word = NULL;
    FILE *output = fopen(output_name, "w+");


    if(input == NULL){
        printf("Error, file cannot be opened!");
        exit(1);
    }
    else{
            // while there is a word in the input file
         while ((fgets(data, 100, input)) != NULL){
             // permutate it and display word being permutated
            word = strtok(data, "\n");
            printf("Word %s is being permutated.\n", word);
            permutate(word, 0, output);


         }



    }

}
// main function
void main(void){
    // calls function for file reading
    getData("AssignmentThreeInput.txt", "AssignmentThreeOutput.txt");

}
