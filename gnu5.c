#include<stdio.h>
#include<math.h>

float j(float n, float z){
    
    if(n == 0){
        return sin(z)/z;
    }
    if(n == 1){
        return (sin(z)/pow(z,2)) - cos(z)/z;
    }
    if(n == 2){
        return (sin(z)/pow(z,2)) - cos(z)/z;
    }
    return ((2*n + 1)*j(n-1,z)/z) - j(n-2, z);
}

int main(){
    FILE *fp = NULL;

    fp = fopen("data/gnu5.dat", "w");

    for (float n = 0; n <= 5; n++) {
        for (float z = 0; z <= 5; z +=0.01) {
            fprintf(fp, "%f\t%f\n", z, j(n,z));
        }
    }
}