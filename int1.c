#include<stdio.h>
#include<math.h>


#define f(x) (atan((x))/((x)*(x)))
#define fl(x) (log(1 + (x)))
#define fh(x) (log(1 + (x)*(x)))

float trapezoidal(float llim, float ulim, int n){
    
    float h = (ulim - llim)/n;

    float s = 0; 
    for(int i = 0; i < n; i++){
        s += f(llim + i*h) + f(llim + (i+1)*h);
    }
    return s*h/2;
}

float simpson(float llim, float ulim, int n){
    float h = (ulim - llim)/n;

    float s = f(llim) + f(ulim);
    for (int i = 1; i < n; i+=2){
        s += 4*f(llim + i*h) + 2*f(llim + (i+1)*h);
    }
    return s*h/3;
}

float gauss(float llim, float ulim, int n){
    float c = (ulim + llim)/2, d = (ulim - llim)/2;

    float x[20], w[20];
    float s = 0;
    #include "gauss.c"
    
    for(int i = 0; i < n/2; i++){
        s += w[i]*(f(c + d*x[i]) + f(c - d*x[i]));    
    }
    return s*=d;
}


float laguerre(float llim, float ulim, int n){
    
    float x[14], w[14];
    float s = 0;
    #include "laguerre.c"
    
    for(int i = 0; i < n/2; i++){
        s += w[i]*fl(x[i]);
    }
    return s;
}


float hermite(float llim, float ulim, int n){
    
    float x[12], w[12];
    float s = 0;
    #include "hermite.c"
    
    for(int i = 0; i < n/2 ; i++){
        s += w[i]*(fh(x[i]) + fh(-x[i]));    
    }
    return s;
}

int main(){
    float a = 5, b = 10;
    int tn = 100, sn = 80000, gn = 6, ln = 10, hn =10;
    printf("trapezoidal: %f\n", trapezoidal(a,b, tn));
    printf("simpson: %f\n", simpson(a,b, sn));
    printf("gauss: %f\n", gauss(a,b, gn));
    printf("laguerre: %f\n", laguerre(a,b, ln));
    printf("hermite: %f\n", hermite(a,b, hn));

    return 0;
}