#include<stdio.h>
#include<math.h>

#define pi 3.14159

float U(int n, float x){
    if(n == 0){
        return 1;
    }
    if(n = 1){
        return 2 * x;
    }

    return 2*x*U(n-1, x) - U(n-2,x);
}

float U4(float x){
    return U(4, x);
}




int main(){
    float inc = 0.1;
    for(float x = -1;  x <= 1.1; x+=inc){
        float x1 = x, x2 = x+inc, x3, z;
        if(U4(x)*U4(x+inc) < 0){
            do{
                x3 = (x1*U4(x2) - x2*U4(x1))/(U4(x2) - U4(x1));
                x1 = x2;
                x2 = x3;
                z = fabs(x1 - x2);
            } while(z > 0.00001);
            printf("x=%f\troot=%f\tf=%f",x,x3);
        }
    }
    return 0;
}