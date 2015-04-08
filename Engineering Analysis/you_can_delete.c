#include <stdio.h>
#include <stdlib.h>

void main(void){int choice = 0;
    int choice2 = 1;
    char name[50];

    //int id_ref = -9999999;
   // char *name_ref = &name;

      //  printf("PREVIOUS: %s\n\n", rear->prev->name);

        while(choice2 != 5){
       // front = create_list(front, rear);
printf("1. Insert\n2. Display\n3. Delete by ID\n4. Delete by Name\n5. Exit\n");
    scanf("%d", &choice);
 // fgets(choice, sizeof(choice), stdin);
    if(choice == 1){
        //rear = insert_nd(front, rear);
    }
    else if(choice == 2){
      //  display_list(front, rear);
    }
    else if(choice == 3){
        printf("Please enter the ID you would like to delete.\n\n");
//        scanf("%d", &id_ref);
    //    delete_id(front, rear, id_ref);
    }
    else if(choice == 4){
        printf("Please enter the name you would like to delete.\n\n");
        fgets(name, sizeof(name), stdin);
        //delete_name(front, rear, &str);

}
        }
}


