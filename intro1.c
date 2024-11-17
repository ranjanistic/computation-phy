#include<stdio.h>
#include<math.h>

#define PI 3.14159

int main(){
    FILE *fpsin = fopen("data/intro1sin.dat","w"), *fpcos = fopen("data/intro1cos.dat", "w"), *fptan = fopen("data/intro1tan.dat", "w");

    for(float x = 0; x <= PI/4; x +=(PI/100)){
        fprintf(fpsin, "%f\t%f\n", x, sin(x));
        fprintf(fpcos, "%f\t%f\n", x, cos(x));
        fprintf(fptan, "%f\t%f\n", x, tan(x));
    }
    fclose(fpsin);
    fclose(fpcos);
    fclose(fptan);
    return 0;
}