#include<stdio.h>
#include<math.h>

float j(float n, float z){
    float res;
    if(n == 0){
        res = sin(z)/z;
    } else if(n == 1){
        res = (sin(z)/pow(z,2)) - cos(z)/z;
    } else {
        res = ((2*n + 1)*j(n-1,z)/z) - j(n-2, z);
    }
    return res;
}

int main(){
    FILE *fp = NULL;

    fp = fopen("data/gnu5.dat", "w");

    for (float z = 0.5; z <= 5; z +=0.01) {
        float j0 = j(0, z);
        float j1 = j(1, z);
        fprintf(fp, "%f\t%f\n", z, j0);
        fprintf(fp, "%f\t%f\n", z, j1);
        for (float n = 1; n <= 5; n++) {
            float j2 = ((2*n + 1)*j1/z) - j0;
            fprintf(fp, "%f\t%f\n", z, j2);
            j0 = j1;
            j1 = j2;
        }
    }
}