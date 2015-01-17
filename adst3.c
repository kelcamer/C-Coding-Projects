#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_WORDS 5
struct mys{
char *language;
int total_words;
char book[MAX_WORDS][20];


};
void add_word2(char *word, struct mys *list3){
    int found = -99999;
    if(list3->total_words == MAX_WORDS){
                printf("List Full, Word not added.\n");
    }
    else{

        if(list3->total_words == 0){
                found = 0;
                strcpy(list3->book[0], word);
                list3->total_words++;
        }
        else{
        int x = 0;
        for(x=0;x < list3->total_words; x++){

            if(strcmp(list3->book[x], word) == 0){
                found = 1;

            }
            else{
                found = 0;
                strcpy(list3->book[x], word);
                list3->total_words++;
                }



        }
    }
    }
      printf("Words: %d\n", list3->total_words);
    printf("Found: %d\n", found);

}
void display5(struct mys list2){
    int c = 0;
    for(c=0;c < list2.total_words;c++){

        printf("%s", list2.book[c]);
    }

}
/*
a       a
b       b
c       c
d       d
e       e



*/
void equal_lists(struct mys list1, struct mys list2){

    int i, j;
    int match = -99999;
    if(strcmp(list1.language, list2.language) == 0){
        if(list1.total_words == list2.total_words){
            for(i = 0; i < list1.total_words; i++){
                for(j = 0; j < list1.total_words; j++){
                if(strcmp(list1.book[i], list2.book[j]) == 0){
                    match = 1;
                    i++;
                }
                else{
                    match = 0;
                }
                }
            }

        }
    }
    printf("Match: %d\n", match);
//return match;

}


void main(void){
struct mys *li, *li2 = NULL;
//li->total_words = 0;
//li2->total_words = 0;
//add_word2("hello", &li);
//add_word2("hello", &li);//add_word2("TEST", &li2);
//add_word2("hellow", &li);
//add_word("hello", &li2);
//display5(*li);
//li->language = "English";
//li2->language = "English";
//li->total_words = 6;
//li2->total_words = 6;
//equal_lists(*li, *li2);

}
