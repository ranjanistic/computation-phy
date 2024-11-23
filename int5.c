#include<stdio.h>
#include<math.h>

#define pi 3.14159

float f(float x, float z){
    return cos(z*cos(x));
}

float simpson(float z){
    float ulim =  2*pi, llim = 0;
    int n = 800;
    float h = (ulim - llim)/n;
    float s = f(ulim, z) + f(llim, z);
    for(float i = 1; i < n; i++){
        s+= 4*f(llim + i*h, z) + 2*f(llim + (i+1)*h,z);
    }
    return s*h/3;

}

float J(float z){
    return simpson(z);
}

float secant(float zl, float zr, float acc){
    float z1 = zl, z2 = zr, z3, z;
    do {
        z3 = (z1*J(z2) - z2*J(z1))/(J(z2) - J(z1));
        z1 = z2;
        z2 = z3;
        z = fabs(z1 - z2);
    }while(z > acc);
    return z3;
}

int main(){
    float zinc = 0.1;
    for(float z = 0; z <= 12; z+=zinc){
        if(J(z)*J(z+zinc) < 0){
            printf("root : %f\n", secant(z, z+zinc, 0.001));
        }
    }
    return 0;
}