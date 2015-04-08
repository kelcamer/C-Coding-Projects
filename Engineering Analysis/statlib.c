/*
Kelsey Cameron
Creating a Statistical Library: Part A of Assignment 2 - Computer Analysis with John Edison
2/28/15 - 3/2/15
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mean_var, variance_var, stand_dev_var = 0.0;

// adds all numbers and divides them
double static mean(int totnum, double data[]){

        double total = 0;
        int count = 0;
    for(count = 0; count < totnum; count++){
        total+= data[count];        }
        total /= totnum;
        mean_var = total;
        return total;
}
// subtracts each  number from the mean, squares it, then divides it by the total num of num
double static variance(int totnum, double data[]){

	int a;
	double var = 0.0;
	double temp = 0.0;
    double temp_sq = 0.0;
	for(a = 0; a < totnum; a++){
    temp = (data[a] - mean_var);
    temp_sq = temp * temp;
    var += temp_sq;
	}

	var /= totnum;

	variance_var = var;
	return var;

}
// this is always the sqrt of variance
double static stdDev(int totnum, double data[]){

	double sd=0.0;
	sd= pow(variance_var, 0.5);
	return sd;

}

void static sort(int totnum, double data[]){
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
// reassign min val if the current one is smaller
double static minValue(int totnum, double data[]){
    int x = 0;
    double min_val = 99999;
    for(x = 0; x < totnum; x++){
        if(min_val > data[x]){
            min_val = data[x];
        }

    }
    return min_val;
}
// reassign max val if the current one is bigger
double static maxValue(int totnum, double data[]){
    int x = 0;
    double max_val;

    for(x = 0; x < totnum; x++){
        if(max_val < data[x]){
            max_val = data[x];
        }
    }
    return max_val;
}
// checks to see if total number of elements is odd or even
// if odd, median is one in the middle
// if even, take the two closest to middle, add, and divide by two.
double static median(int totnum, double data[]){
    double median = 0.0;
   //printf("\n\nAfter Sort\n");
    int i, j = 0;
    int n = totnum;

   for(i=0;i<n;i++){

            if((n % 2 != 0) && (n / 2 == i)){
				median = data[i];

			}
			else if(n / 2 == i){
				median = (data[i-1] + data[i])/2;
			}

		}

		return median;


}


/*
Note to John Edison and Ta's:
It is very hard to see these comments, and I'm not sure if this is because of my computer screen,
or if it is because I have bad vision.   I'm generally a good speller, but please excuse any spelling mistakes
in my comments.
Thanks



*/

