#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int fact(int n){
    int i = n - 1;
    int res = n;
    while(i >= 1){
        res*=(i--);
    }
    return res;
}

int main() {
    FILE *fp = fopen("data/intro6.dat", "w");
    int n = 10;
    fprintf(fp, "factorial of %d = %d\n", n, fact(n));
    fclose(fp);
    return 0;
}