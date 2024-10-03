#include<stdio.h>
#include<math.h>

float j(float n, float z){
    FILE *fp = fopen("j.log", "a");
    FILE *fpw = fopen("j.log", "w");
    fprintf(fpw, "");
    float res;
    if(n == 0){
        res = sin(z)/z;
    } else if(n == 1){
        res = (sin(z)/pow(z,2)) - cos(z)/z;
    } else {
        res = ((2*n + 1)*j(n-1,z)/z) - j(n-2, z);
    }
    fprintf(fp, "j called: n=%f,z=%f,j=%f\n", n, z, res);
    fclose(fp);
    fclose(fpw);
    return res;
}

int main(){
    FILE *fp = NULL;

    fp = fopen("data/gnu5.dat", "w");

    for (float n = 0; n <= 5; n++) {
        for (float z = 0.5; z <= 5; z +=0.01) {
            fprintf(fp, "%f\t%f\n", z, j(n,z));
        }
    }
}