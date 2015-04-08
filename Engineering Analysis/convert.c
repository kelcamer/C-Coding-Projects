#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// begin main function, take in no input.
void main(void){
// defines variables
int choice = 0;
double miles = 0.0;
double km = 0.0;

// user prompt to determine which you are converting from.
    printf("Press 1 to convert from kilometers to miles.\n");
    printf("Press 2 to convert from miles to kilometers.\n");
// scanning in the user's choice.
    scanf("%d", &choice);
// conditional statement to choose between 1 or 2.
if(choice == 1){
    printf("Please enter the length in kilometers.\n");
    scanf("%lf", &km);
    // algorithm to convert to miles
    miles = km * 4.97097/8;
    // prints result
    printf("%lf kilometers equals %lf miles.\n", km, miles);
}
else if(choice == 2){
    printf("Please enter the length in miles.\n");
    scanf("%lf", &miles);
    // algorithm to convert to km    km = miles * 8/4.97097;
    // prints result
    printf("%lf miles equals %lf kilometers.\n", miles, km);

}


}
