#include<stdio.h>
#include<math.h>


#define pi 3.14159

int fact(int n){
    int i = n;
    int out = 1;
    while (i > 0){
        out*=i;
        i--;
    }
    return out;
}

float f(float th, float z, float n){
    return cos(z*cos(th))*pow(sin(th), 2*n+1); // d(th)
}


float simpson(float z, float N, float ulim, float llim){
    int n = 800;
    float h = (ulim - llim)/n;
    float s = f(ulim, z, N) + f(llim, z, N);

    for(int i = 1; i < n; i+=2){
        s+= 4*f(llim + i*h,z, N) + 2*f(llim + (i+1)*h, z, N);
    }
    return s*h/3;
}

float J(float n, float z){
    return (pow(z, n)/(pow(2, n+1)* fact(n))) * simpson(z, n, 0, pi);
}

float secant(int n, float zl, float zr, float acc){
    float z1 = zl, z2 = zr, z3, z;
    do {
        z3 = (z1*J(n, z2) - z2*J(n, z1))/(J(n, z2) - J(n, z1));
        z1 = z2;
        z2 = z3;
        z = fabs(z1 - z2);
    } while(z > acc);
    return z3;
}

int main(){
    int n = 2;
    float zinc = 0.01;
    for(float z = 0; z <= 10; z+=zinc){
        if(J(n, z) == 0){ // if root exactly at z
            printf("root=%1.2f\n", z);
        } else if(J(n, z)*J(n, z+zinc) < 0){
            printf("root=%1.2f\n", secant(n, z, z+zinc, 0.0001));
        }
    }
    return 0;
}