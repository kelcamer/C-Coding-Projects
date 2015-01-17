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

student *front, *rear = NULL;



student* newnd(void){
    return (student *)malloc(sizeof(student));
}

    int count;
/*
student* push(student *first, student *last, int loop, int num){
    first = NULL;
    student *temp;
    for(count = 0; count < loop; count++){
    last = newnd();
    last->laptopID = num;
    printf("NUM: %d\n", num);
        if(first == NULL){
            first = temp = last;
          //  printf("FIRST: %d", first->laptopID);
                   }
        else if(first != NULL){
            temp->next = last;
            //last->prev = temp;
            temp = last;
            //totalnodes++;

        }

        fflush(stdin);
    //first->prev = NULL;
    last->next = NULL;


    }
    rear = last;
   return first;
}*/
student* push(student *first, student *last, int loop, int num){
    student *nxtND;
    student *temp2;
    int count;
    if(count < loop){
    if(first == NULL){

        first =nxtND  = temp2 = last = newnd();
        first->laptopID = num;
        count++;
    printf("%d", first->laptopID);
    }
    else{
            nxtND = first->next;
            first->next = push(nxtND, last, loop, num);

    return;
    }
        return first;


    }
}

void print_stack(student *first){
  //  student *temp2 = first;

            printf("%d\n", first->laptopID);

    if(first != NULL){
        if(first->next != NULL){

            print_stack(first->next);
        }
        else{

            return;
        }



    }
    else{
        printf("Stack is NULL\n");
    }

}
void main(void){
            int data = 0;
            int count = 0;
            int total_students = 0;
	FILE *in = fopen("program4.txt", "r");
	 if (in == 0)
            {
              printf("Error! Could not open file\n");
              exit(-1); // must include stdlib.h
            }
            fscanf(in,"%d", &total_students );
            for(count = 0; count < total_students; count++){
//            printf("Hello");
            fscanf(in, "%d", &data);
            front = push(front, rear, count, data);
            }

             //   print_stack(front);

printf("FIRST:\n%d", front->laptopID);
//printf("SECOND: /n%d", front->next->laptopID);
fclose(in);
}
