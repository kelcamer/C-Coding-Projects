#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
TODO: Format output and change name of file
TODO: Create Reverse Function
TODO: Add comments
TODO: Ask about push


*/


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
typedef struct mylist list;


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
list* reverse(list *first, list *last){
//    list *temp4 = first;
   // if(first != last){
   // if(first!=NULL){
      //  first = last;
     //   first->next = first->prev;
       // first->next = last->next;
      //  first->prev = last->prev;
        //last = temp4;
      //  last->next = temp4->next;
      //  last->prev = temp4->prev;
       // first->next = reverse(first->next, last);

   // }
   // else{
     //   printf("End of list.\n");
//        free(temp4);
   // return first;

    //}

    //else{
      //  printf("You have one node in your list.  You cannot reverse it.\n");
        //return first;
    //}




}
list* reverse_list(list *last_ref, list *cur, list *new_one){
    if((cur!=NULL) && (last_ref!= NULL) && (new_one!=NULL) && (cur != last_ref)){
         new_one = last_ref;
      //  new_one->next = last->prev;
        printf("\t Produce:\t%s\n", new_one->produce);
        printf("\t    Type:\t%s\n", new_one->type);
        printf("\tIn stock:\t%s\n", new_one->soldBy);
        printf("\t   Price:\t%lf\n", new_one->price);
        printf("\tQuantity:\t%d\n\n\n", new_one->quantityInStock);
      //  if(new_one->next != NULL)
        new_one->next = reverse_list(last_ref->next, cur, new_one->next);

           }
            else{
            printf("List is empty.");

            }

        return new_one;

//display_list(new_one, last);
      //  new_one->prev = first;

  //  return new_one;

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
list* get_from_file(char *file_name, list *first, list *last){
    FILE *io = fopen(file_name, "r");
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
        printf("Can't open input file in.list!\n");
        exit(1);

    }
    else{

    while ((fgets(data, 100, io)) != NULL){

    produce_point = strtok(data, comma);
    type_point = strtok(NULL, comma);
    sold_by_point = strtok(NULL, comma);
    price_point = strtok(NULL, comma);
    in_stock_point = strtok(NULL, comma);

   // printf("Count: %d\n", count);
        last = newnd();
        strcpy(&last->produce, produce_point);
        strcpy(&last->type, type_point);
        strcpy(&last->soldBy, sold_by_point);

        last->price = atof(price_point);
        last->quantityInStock = atoi(in_stock_point);
    //    printf("\t Produce:\t%s\n", last->produce);
     //   printf("\t    Type:\t%s\n", last->type);
     //   printf("\tIn stock:\t%s\n", last->soldBy);
      //  printf("\t   Price:\t%lf\n", last->price);
      //  printf("\tQuantity:\t%d\n", last->quantityInStock);
       count++;
   if(first == NULL){
       temp = first = last;
    }
    else{
        temp->next = last;
        last->prev = temp;
        temp = last;

    }

  //  int c = 0;
   //  while((c = getchar()) != '\n' && c != EOF);
    }
    }
    first->prev = last;
    last->next = first;
    printf("List created.\n");
    return first;
}
void display_list(list* first, list* last){

        printf("\t Produce:\t%s\n", first->produce);
        printf("\t    Type:\t%s\n", first->type);
        printf("\tIn stock:\t%s\n", first->soldBy);
        printf("\t   Price:\t%lf\n", first->price);
        printf("\tQuantity:\t%d\n\n\n", first->quantityInStock);

        if(first->next != last->next){
            display_list(first->next, last);
        }
        else{
            printf("End of List.\n");
        }




}
/*list* reverse_list(list *first, *rear){


}*/
void write_to_file(list *first, list *last, FILE *output){
    if(output == NULL){
        printf("Cannot open.  ERROR");
        exit(1);
    }
    else{
        fprintf(output, "\t Produce:\t%s\n", first->produce);
        fprintf(output, "\t    Type:\t%s\n", first->type);
        fprintf(output, "\tIn stock:\t%s\n", first->soldBy);
        fprintf(output, "\t   Price:\t%lf\n", first->price);
        fprintf(output, "\tQuantity:\t%d\n\n\n", first->quantityInStock);

       if(first->next != last->next){
            write_to_file(first->next, last, output);
       }
       else{
            fprintf(output, "End of list.\n");
       }
    }
}
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
void main(void){
    FILE *out = fopen("output.txt", "w");
    list *front, *rear, *temp, *temp2;
    temp = NULL;
    temp2=NULL;
    front = NULL;
    rear = NULL;
    char data[3];
    char *num;
    int number;
    int c = 0;
 while(number!=5){
    printf("Would you like to:\n1. Get Data from File.\n2. Display List.\n3. Reverse List.\n4. Write List to File.\n5. Exit.\n");
    fgets(data, 2, stdin);
    num = strtok(data, "/n");
    number = atoi(num);
   // while((c = getchar()) != '\n' && c != EOF);    getchar();

        if(number == 1){
        front= get_from_file("AssignmentTwoInput.txt", front, rear);
        rear = front->prev;
        }
        else if(number == 2){
        display_list(front, rear);
        }
        else if(number == 3){
      //  front->next = NULL;
     //   rear->prev = NULL;
       list *temp3 = NULL;

        temp2 = front;
        temp = rear;
        temp->next = rear->prev;

       /* front = reverse_list(rear, front, temp);
        rear = temp2;
        front->next = rear;
        rear->prev = front;
        printf("HI");
 //  int c = 0;
   //  while((c = getchar()) != '\n' && c != EOF);
*/


        display_list(front, rear);
     //   front->prev = rear;
         //       printf("New one: %s\n", front->prev->produce);
      //  display_list(front, rear);
        }        else if(number == 4){
        write_to_file(front, rear, out);
        }
        else if(number == 5){
        printf("Exiting.");
        exit(1);
    }
    }

//    front = pop(front, front->prev);
 //   front = push(front, front->prev);
     //   printf("%s", front->prev->produce);
//    display_list(front, front->prev);


}
