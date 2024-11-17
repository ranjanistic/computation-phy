#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int fact(int n){
    if(n == 0) return 1;
    int i = n - 1;
    int res = n;
    while(i >= 1){
        res*=(i--);
    }
    return res;
}

int main() {
    
    FILE *fp = fopen("data/intro8.dat", "w");
    float a = 1, b = 0, c = -4;
    
    float D = pow(b,2) - 4*a*c;
    if(D < 0){
        printf("D < 0. Not real roots");
        return 0;
    }
    float root1 = (-b + sqrt(D) )/ (2*a);
    float root2 = (-b - sqrt(D)) /(2*a);
    fprintf(fp, "roots = %f, %f\n", root1, root2);
    fclose(fp);
    return 0;
}