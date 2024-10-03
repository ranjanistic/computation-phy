#include<stdio.h>
#include<math.h>

#define pi 3.14159


float scos(float x, float acc){
    float k = 0, s = 1, t = 1;
    do {
        t *= -x*x/((2*k + 2)*(2*k + 1));
        s+=t;
        k++;
    } while(fabs(t/s) > acc);
    return s;
}

int main(){

    FILE *fp = fopen("data/series2.dat", "w");
    float s = 0, t = 1;

    for(float x = 0; x <= 2*pi; x+=pi/100){
        fprintf(fp, "%f\t%f\t%f\n", x, scos(x, 0.0001), cos(x));
    }
    fclose(fp);
    return 0;
}