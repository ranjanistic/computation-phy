#include<stdio.h>
#include<math.h>

#define pi 3.14159

float f(float A, float x){
    return 1/(1 - pow(sin(A/2),2)*pow(sin(x),2));
}

float simpson(float llim, float ulim, float n, float A){
    float h = (ulim - llim)/n;
    float s = f(A, llim) + f(A, ulim);
    for(float i = 1; i <= n; i+=2){
        s += 4*f(A, llim + i*h) + 2*f(A, llim + (i+1)*h);
    }
    return s*h/3;
}

int main(){
    float a= 0, b = pi/2;
    float n = 80000;
    FILE *fp = NULL;
    fp = fopen("data/int2.dat", "w");
    for(float A = 0.01; A < pi; A+=(pi/100)){
        float t = 4*simpson(a, b, n, A);
        float t1 = 2*pi*(1 + pow(A/4, 2));
        fprintf(fp, "%f\t%f\t%f\t%f\n", A, t, t1, 100*(t- t1)/t);
    }
    fclose(fp);
    return 0;
}
