// Kelsey Cameron
// Using C to calculate various statistical numbers
#include <stdio.h>
#include <stdlib.h>

void main(){
	int data_set = 0;
	int numofnum = 0;
	float mean = 0.0;
	float mode = 0.0;
	float median = 0.0;
	float total = 0.0;
	
	
	printf("How many data sets are we calculating?\n");
	scanf("%d", data_set);
	int i;
	int j;
	for(i = 0; i < data_set; i++){
		printf("How many numbers are there in the data set?\n");
		scanf("%d", numofnum);
		int data_set[numofnum];	
		for(j = 0; j < numofnum; j++){
			
			printf("Please enter each number.");
			scanf("%lf", data_set[j]);
			total += data_set[j];
			
			
		}
		mean = total / numofnum;
		printf("The mean is: %lf", mean);
		
	}
	
	
	
	
}
