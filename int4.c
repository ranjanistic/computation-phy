#include<stdio.h>
#include<math.h>

#define pi 3.14159

float f(float x, float t){
    return cos(pow(x, 1.5)*cos(t)) * pow(sin(t),3);
}

float simpson(float x){
    float llim = 0, ulim = pi, N = 800;
    float h = (ulim - llim)/N;
    float s = f(x, llim) + f(x, ulim);
    for(int i = 1; i < N; i++){
        s += 4*f(x, llim + i*h) + 2*f(x, llim + (i+1)*h);
    }
    s = s*h/(3*2*pi);
    printf("%f\t%f\n",x, s);   
    return s;
}

float F(float x){
    return simpson(x);
}

float secant(float xl, float xr, float acc){
    float x1 = xl, x2 = xr, z, x3;
    do{
        x3 = (x2*F(x1) - x1*F(x2))/(F(x2) - F(x1));
        x1 = x2;
        x2 = x3;
        z = fabs(x1 - x2);
    } while (z > acc);
    return x3;    
}

int main(){

    float xinc = 0.001;
    float lroot;
    int i = 0;
    for(float x = 0; x <= 10; x+=xinc){
        if(F(x)*F(xinc) < 0){
            float root = secant(x, x+xinc, 0.0001);
            if(i == 0){
                lroot = root;
            } else if(root < lroot){
                lroot = root;
            }
            i++;
        }
    }
    printf("total roots=%d\n", i);
    printf("lowest root=%f\n", lroot);
    return 0;
}