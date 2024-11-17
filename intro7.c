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
    FILE *fp = fopen("data/intro7.dat", "w");
    float ncr = 0;
    float npr = 0;
    int n = 10, r = 4;
    if(r > n) return printf("r should be <= n");
    npr = fact(n)/fact(n-r);
    ncr = npr/fact(r);
    fprintf(fp, "%dC%d = %10.3f\n", n,r, ncr);
    fprintf(fp, "%dP%d = %10.3f\n", n,r, npr);
    fclose(fp);
    return 0;
}