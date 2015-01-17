// Kelsey Cameron	
#include <stdio.h>
#include <stdlib.h>

int main(){
	double fahr = 0.0;
	double cel = 0.0;
	int ipt = 0;
	
	
	while(ipt != 3){
	
	printf("Convert from F to C:   Type in 1.  \nConvert from C to F:  Type in 2\n");
	scanf("%d", &ipt);
	
	
	if(ipt == 1){
	
	printf("Please enter the temperature in Fahrenheit.\n");
	scanf("%lf", &fahr);
	cel = ((fahr - 32) * 100)/180;
	printf("Celcius Value: %lf\n", cel);
	}
	else if(ipt == 2){
	printf("Please enter the temperature in Celcius.\n");		
	scanf("%lf", &cel);
	
	fahr = (cel * 180/100) + 32;
	printf("Fahrenheit Value: %lf\n", fahr);
	}
	
	
	}
	system("pause");
	return 0;
	
	
}
