#include <stdio.h>
#include <stdlib.h>

typedef struct ucfClass {
char ID[10]; // class ID, ex: "COP-3502"
char days[6]; // a combination of "MTWRF" (days)
char time[20]; // class time, ex: "10:30 AM - 12:00 PM"
} class;
typedef struct ucfStudent {
char lastName[21]; // student last name
char firstName[21]; // student first name
int ID; // student ID
int laptopID; // serial number of the laptop the student picks up
int errorCode; // flag to determine if they will make mistakes
int numClasses; // number of classes the student will register
class *classes; // array of said classes (2 be dynamically allocated)
int enterTime; // time student arrived, in minutes, after 12:00 PM
int timeLeft; // countdown timer to measure the 5 min. reg. process
int timeRegistered; // Time student finished reg. and left Registrar
struct ucfStudent *next; // pointer to next student in queue
} student;

student *front, *rear, *temp = NULL;
int count = 0;


student* newnd(void){
   return  (student *)malloc(sizeof(student));

     //  return temp2;
}

student* insert(student *first, student *last){
    FILE *in = fopen("p.txt", "r");
	 if (in == 0)
            {
              printf("Error! Could not open file\n");
              exit(-1); // must include stdlib.h
            }

    if(first == NULL){
    first = newnd();
    printf("Please enter a number:\n");
    sscanf(in, "%d", &first->laptopID);
    temp = first;
    first->next = NULL;
    return first;
    }
    else if(first != NULL){
    first->next = insert(first->next, last);


    }
    rear = temp;
    rear->next = NULL;
//    first->prev = NULL;
   // free(temp);
    fflush(stdin);

return first;
}

void printlist(student *f){
    if(f == NULL){
        return;
    }
    else{
        printf("%d->", f->laptopID);
        printlist(f->next);
    }
}
void main(void){
       int loop = 0;
    printf("How many numbers do you want?\n");
    scanf("%d", &loop);
    for(count = 0; count < loop; count++){
    front = insert(front, rear);

    }
    printlist(front);
}
