// Kelsey Cameron
// Check if scanned value is prime.
#include <stdio.h>
#include <stdlib.h>
int main(){
	int n = 0;
	int test = 1;
	printf("How many numbers are we testing?");
	scanf("%d", &n);
	int i;
	for(i = 0; i < test; i++){
		printf("Please enter a number.\n");
		scanf("%d", &test);
		/*
		if(((test / 2) == 1) || ((test / 3) == 1) || ((test / 5) == 1)  || ((test / 7) ==1) || ((test / 11) == 1 || ((test / 13) == 1)) || ((test / 17) == 1) || ((test / 19) == 1)){

			printf("PRIME: %d\n", test);
			
		}	
		
	*/
	if((test % 2) != 0){
		if(((test % (i - 2)) != 0) && ((i-2) >= 0))
		{
			printf("PRIME: %d\n", test);
		}
		
		
	}	
	}
		
	
	
//	getchar();
	return 0;

}
