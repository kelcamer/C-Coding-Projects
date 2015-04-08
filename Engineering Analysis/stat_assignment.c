#include <stdio.h>
#include <stdlib.h>

double mean_var, variance_var, stand_dev_var = 0.0;


//void sort(int totnum, double data[]) //sorts the array data


//double median(int totnum, double data[]) //returns the median value
double mean(int totnum, double data[]){
        double total = 0;
        int count = 0;
    for(count = 0; count < totnum; count++){
        total+= data[count];        }
        total /= count;
//        mean = total;
        printf("Mean: %0.2lf\n", total);
        return total;

}
double variance(int totnum, double data[]){
	int a;
	double var;
	for(a = 0; a < totnum; a++){
		var += pow((data[a] - mean_var), 2);
	}
	var /= totnum;
	printf("Variance: %0.3lf\n\n", var);
	return var;

}
double stdDev(int totnum, double data[]){

	double sd=0.0;
	sd= pow(variance_var, 0.5);
	printf("Standard Deviation: %0.3lf\n\n", sd);
	return sd;

}
void sort(int totnum, double data[]){


   int i,j, n = 0;
   n = totnum;
   double tmp;

   // Bubble sorting
   // Compares the first to the second, second to the third and so forth
   // Worst kind of sorting method n^n O notation
   // However it suits my purpose here
   for(i=0;i<n;i++)
   {
    for(j=i+1;j<n;j++){
    	// for all the data of i, check all data of j
       if( data[i] > data[j]){
      tmp = data[i];
      data[i] = data[j];
      data[j] = tmp;
       }
    }
   }



}

double minValue(int totnum, double data[]){
    int x = 0;
    double min_val = 99999;
    for(x = 0; x < totnum; x++){
        if(min_val > data[x]){
            min_val = data[x];
        }

    }
    return min_val;
}
double maxValue(int totnum, double data[]){
    int x = 0;
    double max_val;

    for(x = 0; x < totnum; x++){
        if(max_val < data[x]){
            max_val = data[x];
        }
    }
    return max_val;
}
double median(int totnum, double data[]){
    double median = 0.0;
   printf("\n\nAfter Sort\n");
    int i, j = 0;
    int n = totnum;

   for(i=0;i<n;i++){

      printf("%0.1lf, ",data[i]);
            if((n % 2 != 0) && (n / 2 == i)){
				median = data[i];

			}
			else if(n / 2 == i){
				median = (data[i-1] + data[i])/2;
			}

		}

				printf("Median: %0.3lf\n\n", median);
		return median;


}

void main(){

    double array[] = {6, 9, 8, 19, 27, 188};
        mean_var = mean(6, array);
        variance_var = variance(6, array);
        stdDev(6, array);
        sort(6, array);
        double min = minValue(6, array);
        double max = maxValue(6, array);
        printf("Min: %0.2lf", min);
        printf("Max: %0.2lf", max);
        median(6, array);
    //reorder(array, 5);



}
