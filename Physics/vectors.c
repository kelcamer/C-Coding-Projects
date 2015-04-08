#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double final_x, final_y, final_z = 0;

    double inputx, inputy, inputz = 0.0;
    double mag = 0.0;
void get_mag(double x, double y, double z){
    double total = 0.0;
    inputx = x;
    inputy = y;
    inputz = z;
    x = pow(x, 2);
    y = pow(y, 2);
    z = pow(z, 2);
    total = x+y+z;    //printf("z:%d\n", z);
     printf("Total:%lf\n", total);    mag = sqrt(x+y+z);
    if(mag == 1){
        printf("This is a unit vector.\n");

    }
        get_unit_vector(x,y,z);

    //return 0;
};
void get_unit_vector(int x, int y, int z){
    printf("Magnitude of the Vector: %lf\n\n", mag);
         printf("X, Y, Z:%lf, %lf, %lf\n", inputx, inputy, inputz);
    final_x = inputx / mag;
    final_y = inputy / mag;    final_z = inputz / mag;
    printf("Your unit vector is:\n<%lf, %lf, %lf>\n", final_x, final_y, final_z);
};
void check_unit_vector(double x, double y, double z){
//if()


};
void main(){
    int ipt = 1;
    while(ipt){
        printf("Please enter three values, x, y, and z.\n If your vector is two dimensional, just enter 0 for z.\n");
        scanf("%lf", &inputx);
        scanf("%lf", &inputy);        scanf("%lf", &inputz);
        get_mag(inputx,inputy,inputz);
        printf("Would you like to continue? \n1=Yes\n0=No\n");
        scanf("%d", &ipt);



    }

}
