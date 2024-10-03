#include<stdio.h>
#include<math.h>

#define pi 3.14159

int main(){

    float  t, s, acc = 0.0001,s1;
    int i;

    FILE *fp = fopen("data/series4.dat", "w");

    for(float z = 0; z <= 1; z+=0.05){

        t = z; s = t; i = 1;
        do {
            t*= -pi*pi*pow(z, 4)/(4 * i + 1);
            s+=t;
            i+=1;
        } while(fabs(t/(s+acc)) > acc);
        s = cos(pi*z*z/2)*s;
        fprintf(fp, "%f\t%f\n", z, s);
    }
    fclose(fp);


    return 0;
}