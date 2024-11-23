#include<stdio.h>
#include<math.h>

float f(float r, float E, float m, float l, float k){
    float V = -k/r;
    return 1/(pow(r, 2)*sqrt((2*m*E/pow(l,2)) - (2*m*V/pow(l,2)) - 1/pow(r,2)));
}

float gauss(float llim, float ulim, int n, float E){

    float x[20], w[20];
    float c = (llim + ulim)/2, d= (ulim - llim)/2;
    #include "gauss.c"
    float s = 0;
    for(int i = 0; i <= n/2 - 1; i++){
        s += w[i]* (f(c + d*x[i], E, 1, 1,1) + f(c - d*x[i], E, 1,1,1));
    }
    
    return s*=d;
}

int main(){

    FILE *fp = NULL, *fp1 = NULL;
    fp = fopen("data/int3a.dat", "w");
    fp1 = fopen("data/int3b.dat", "w");

    float E = -0.25;
    for(float r = 0.61; r <= 3.4; r+=0.01){
        float th = gauss(0.60, r, 12, E);
        // printf("%f\n", th);
        float x = r*cos(th);
        float y = r*sin(th);
        fprintf(fp, "%f\t%f\n", x, y);
    }
    E = 0;
    for(float r = 0.51; r <= 5.0; r+=0.01){
        float th = gauss(0.50, r, 12, E);
        // printf("%f\n", th);
        float x = r*cos(th);
        float y = r*sin(th);
        fprintf(fp1, "%f\t%f\n", x, y);
    }

    fclose(fp);
    fclose(fp1);
    return 0;
}