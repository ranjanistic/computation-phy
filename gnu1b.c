#include<stdio.h>
#include<math.h>

#define pi 3.14

int main(){
    float x, y, t;

    FILE *fp = NULL;

    fp = fopen("data/gnu1b.dat", "w");

    float x0 = 5, y0 = 5, r = 3;

    for(float t = 0; t<=2*pi; t+=pi/100.0){
        y = y0 + r*sin(t);
        x = x0 + r*cos(t);
        fprintf(fp, "%f\t%f\n", x, y);
    }
    fclose(fp);

    return 0;
}