#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
TODO: Format output and change name of file
*/

// Creating the structure
struct mylist{
    char produce[20];
    char type[20];
    char soldBy[20];
    float price;
    int quantityInStock;
    struct mylist *next;
    struct mylist *prev;
    int data;

};
// using typedef ;) to make creating new nodes easier.
typedef struct mylist list;

// gets the data from the file and returns the node from it.   Node passed is just a new nd
list* get_data(list *new_one){



    const char newline[2] = "\n";
    char produce[21];
    char type[21];
    char soldby[21];
    char price[21];
    char stock[21];
    static int count = 1;
    char *produce_point;
    char *type_point;
    char *sold_by_point;
    char *price_point;
    char *in_stock_point;
     int c = 0;
  //  char data[21];

        printf("Please enter the produce type, with a comma at the end.\n");
        fgets(produce, 20, stdin);
        produce_point = strtok(produce, "\n");
//         while((c = getchar()) != '\n' && c != EOF);
       // printf("%s", produce_point);
        printf("Please enter the type, with a comma at the end.\n");
        fgets(type, 20, stdin);
        type_point = strtok(type, "\n");
    // while((c = getchar()) != '\n' && c != EOF);

        printf("Please enter the units that produce is sold by, with a comma at the end.\n");
        fgets(soldby, 20, stdin);
        sold_by_point = strtok(soldby, "\n");
//     int c = 0;
    // while((c = getchar()) != '\n' && c != EOF);

        printf("Please enter the price, with a comma at the end.\n");
        fgets(price, 20, stdin);
        price_point = strtok(price, "\n");

        printf("Please enter the number in stock, then press enter.\n");
        fgets(stock, 20, stdin);
        in_stock_point = strtok(stock, "\n");

        strcpy(&new_one->produce, produce_point);
        strcpy(&new_one->type, type_point);
        strcpy(&new_one->soldBy, sold_by_point);

        new_one->price = atof(price_point);
        new_one->quantityInStock = atoi(in_stock_point);
        return new_one;
}

list* newnd(void){
    // this is the issue
    list *temp8 = (list *)malloc(sizeof(list));
         //   printf("Creating new node.\n");
    if(temp8 == NULL){
        printf("Sorry, malloc failed :/\n");
        exit(1);
    }
    else{

        return temp8;
    }
}
// Reversing the list
list* reverse_list(list *first, list *last, list *new_one){

    if((last!=NULL) && (first!= NULL) && (new_one!=NULL)){

        // sets first node as last from last list
            new_one = last;
        // sets the links as opposite from last node
            new_one->next = last->prev;
            new_one->prev = last->next;

           }
    else{
        // tells user list is empty
            printf("List is empty.");
            exit(1);
        }
        // keep going until you've traversed circle once
        if(first != last){
            // Go to the next one in the new list and set it equal to the previous in the old list
            new_one->next = reverse_list(first, last->prev, new_one->next);
        }

        new_one->prev = first;

    return new_one;

}

list* get_from_file(char *file_name, list *first, list *last){

    printf("Trying to open file %s.\n", file_name);

    // creates file
    FILE *io = fopen(file_name, "r");
    // creates variables and gives a random address
    const char comma[2] = ",";
    char random_address[100];
    static int count = 1;
    list *temp = NULL;
    char *produce_point = &random_address;
    char *type_point= &random_address;
    char *sold_by_point= &random_address;
    char *price_point= &random_address;
    char *in_stock_point= &random_address;
    char data[101];
    if (io == NULL) {
            // makes sure file exists
        printf("Can't open input file in.list!\n");
        exit(1);

    }
    else{
        printf("Successfully opened file %s.\n", file_name);
    while ((fgets(data, 100, io)) != NULL){
        // uses fgets to get data, keeps going until comma
        produce_point = strtok(data, comma);
        type_point = strtok(NULL, comma);
        sold_by_point = strtok(NULL, comma);
        price_point = strtok(NULL, comma);
        in_stock_point = strtok(NULL, comma);

        // creates newnd()
        last = newnd();

        // copies into the node
        strcpy(&last->produce, produce_point);
        strcpy(&last->type, type_point);
        strcpy(&last->soldBy, sold_by_point);

//        converts to numbers
        last->price = atof(price_point);
        last->quantityInStock = atoi(in_stock_point);
        count++;
   if(first == NULL){
        // if first is null, set equal to the new node
       temp = first = last;
    }
    else{
        // links the list
        temp->next = last;
        last->prev = temp;
        temp = last;

    }

   //  while((c = getchar()) != '\n' && c != EOF);
  //  int c = 0;
    }
    }
    // This is what makes my list circular ;D
    first->prev = last;
    last->next = first;

    return first;
}
void display_list(list* first, list* last, int count){
    // prints
        count++;
        // prints 74 equals signs
        /*
        printf("\n==========================================================================\n");
        printf("    Item #     Produce     Type          Sold By     Price     In Stock\n");
        printf("\n==========================================================================\n");

        */
        printf("     %-5d", count);
        printf("%-16s", first->produce);
        printf("%-15s", first->type);
        printf("%-8s     ", first->soldBy);
        printf("%0.2lf        ", first->price);
        printf("%-8d\n", first->quantityInStock);

    // makes sure next node is not the one you've looped through already
    // TAS: Yes, this is a circular list.   Yes, a slightly different
    // implementation.   It works ;D
        if(first->next != last->next){
            display_list(first->next, last, count);
        }
}

void write_to_file(list *first, list *last, FILE *output, int count){
    // makes sure file exists
    if(output == NULL){
        printf("Cannot open.  ERROR");
        exit(1);
    }
    else{
    // prints to output file
        count++;
        // 74 equals signs
        fprintf(output, "     %-5d", count);
        fprintf(output, "%-16s", first->produce);
        fprintf(output, "%-15s", first->type);
        fprintf(output, "%-8s     ", first->soldBy);
        fprintf(output, "%0.2lf        ", first->price);
        fprintf(output, "%-8d\n", first->quantityInStock);

    // recursively checks if the next node is empty
       if(first->next != last->next){
           // changes first to first->next
            write_to_file(first->next, last, output, count);
       }
       else{
            // Tells when the end of the list is
            fprintf(output, "End of list.\n");
       }
    }
}
// Wasn't required for the assignment, but I added it anyway.
list* push(list *current, list *last){
    printf("Entering push.\n");
    list *temp4 = newnd();
    if(current != NULL){
        temp4 = get_data(temp4);
        last->next = temp4;
        temp4->prev = last;
        last = temp4;
    }
    else{
        temp4 = get_data(temp4);
        temp4->next = NULL;
        temp4->prev = NULL;
    }
     int c = 0;
     while((c = getchar()) != '\n' && c != EOF);
    temp4->next = current;
    current->prev = temp4;

    return current;

}
// wasn't required, added anyway
list* pop(list *first, list *last){
    list *temp2 = last;
    printf("The node containing %s will be deleted.", last->produce);
    if(last != first){
        temp2=last->prev;
        free(last);
        last = temp2;
//        first->prev = last;
  //      last->next = first;
        printf("Entering pop.");
    }
    else{
        free(first);
        free(last);
        printf("List is NULL.\n");
    }
    last->next = first;
    first->prev = last;

    return first;
}

// Main function
void main(void){
    // creates output file
    FILE *out = fopen("AssignmentTwoOutput.txt", "w");
    list *front, *rear, *temp, *temp2;
    // For some reason, setting it to NULL at the end didn't work, so I set it explicitly
    temp = NULL;
    temp2=NULL;
    front = NULL;
    rear = NULL;
    char data[3];
    char *num;
    int number;
    int c = 0;
 while(number!=5){
    // loops and gets user choice
    printf("\n1. Stock Produce Department\n2. Display Produce Inventory\n3. Reverse Order of Produce Inventory\n4. Export Produce Directory\n5. Exit Program\nEnter your choice: ");
    fgets(data, 2, stdin);
    num = strtok(data, "/n");
    number = atoi(num);
    if(number == 5){
        exit(1);
    }
   // while((c = getchar()) != '\n' && c != EOF);    getchar();

        // calls functions
        if(number == 1){
        front= get_from_file("AssignmentTwoInput.txt", front, rear);
        rear = front->prev;
        }
        else if(number == 2){
        printf("\n==========================================================================\n");
        printf("  Item #  Produce          Type        Sold By        Price     In Stock\n");
        printf("\n==========================================================================\n");
        display_list(front, front->prev, 0);
        }
        else if(number == 3){

        // keeps track of front and rear
        temp2 = front;
        temp = front->prev;

        // REVERSES LIST and returns first node, as a circular list ;D
        front = reverse_list(front, rear, temp);
        // displays list
        front->prev = temp2;
        temp2->next = front;
        rear = temp2;
        printf("List is now reversed.\n");

        }        else if(number == 4){
        write_to_file(front, rear, out, 0);
        }
        else if(number == 5){
        printf("Exiting.");
        exit(1);
    }
    }

//    front = pop(front, front->prev);
 //   front = push(front, front->prev);


}
