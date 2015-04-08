// Kelsey Cameron
// Using C to calculate various statistical numbers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getsd(double variance);
double reorder(double values[], int n);
double get_variance(double mean, double values[], int numonum);
int main(){
	int data_set = 0;
	int numofnum = 0;
	int half = 0;
	double mean = 0.0;
	double mode = 0.0;
	double median = 0.0;
	double temp = 0.0;
	double total = 0.0;
	double sd = 0.0;
	double dataitems[100];
	double variance;
	double s[6];
	FILE *in_file = fopen("stat.txt", "r");
	 if (in_file == NULL)
            {
              printf("Error! Could not open file\n");
              exit(1); // must include stdlib.h
            }
	printf("How many data sets are we calculating?\n");
	fscanf(in_file, "%d", &data_set);
	printf("%d", data_set);
	int i;
	int counter = 1;

	int j = 0;

	for(i = 0; i < data_set; i++){
		printf("How many numbers are there in the data set?\n");
		fscanf(in_file, "%d", &numofnum);


			printf("Please enter each number, separated by a break line.\n");
		for(j = 0; j < numofnum; j++){

			fscanf(in_file, "%lf", &dataitems[j]);
		//	printf("TOTAL: %lf\n", total);
			total = total + dataitems[j];
	}

		mean = total / numofnum;

			printf("Total: %0.3lf\n\n", total);
		printf("Mean: %0.3lf\n\n", mean);
printf("Dataitems: %lf", dataitems);
		variance = get_variance(mean, dataitems, numofnum);
		sd = getsd(variance);
		median = reorder(dataitems, numofnum);
		printf("There are %d numbers in this data set.\n", numofnum);
		printf("Median: %lf\n", median);
		int q =0;
		for(q=1; q < 4; q++){
			s[q] = mean + (q * sd);
			printf("%ds = %0.2lf\n", q, s[q]);

		}
		for(q=4; q < 7; q++){
			s[q] = mean - ((q-3) * sd);
			printf("-%ds = %0.2lf\n", q-3, s[q]);

		}
		numofnum = 0;
		temp = 0.0;


	}



return 0;
}
double get_variance(double mean, double list[], int numonum){
	int a;
	double var;
	for(a = 0; a < numonum; a++){
		var += pow((list[a] - mean), 2);
	}

	var /= numonum;
	printf("Variance: %0.3lf\n\n", var);
	return var;

}
double getsd(double variance){
	double sd;
	sd = pow(variance, 0.5);
	printf("Standard Deviation: %0.3lf\n\n", sd);
	return sd;

}
double reorder(double values[], int n){
/*int a = 0;
	double lowest[100];
	double ordered;
	lowest[0] = values[0];
	for(a = 0; a<numonum; a++){
		if(values[a] < lowest[a]){
		lowest[a] = values[a];
		}
	}
	for(a = 0; a<numonum; a++){
		printf("Data set:\n%lf", lowest[a]);
	}
*/

   int i,j;
   double tmp;

   // Bubble sorting
   // Compares the first to the second, second to the third and so forth
   // Worst kind of sorting method n^n O notation
   // However it suits my purpose here
   for(i=0;i<n;i++)
   {
    for(j=i+1;j<n;j++){
    	// for all the values of i, check all values of j
       if( values[i] > values[j]){
      tmp = values[i];
      values[i] = values[j];
      values[j] = tmp;
       }
    }
   }
double median = 0.0;
   printf("\n\nAfter Sort\n");


   for(i=0;i<n;i++){

      printf("%0.1lf, ",values[i]);


	if((n % 2 != 0) && (n / 2 == i)){
				median = values[i];

			}
			else if(n / 2 == j){
				median = (values[i-1] + values[i])/2;
			//	printf("Median: %0.3lf\n\n", median);
			}

		}

		return median;
    //  getch();

}
