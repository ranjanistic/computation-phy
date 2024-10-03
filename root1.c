#include<stdio.h>
#include<math.h>

float f(float x, float a, float b){
    return exp(a*x) - b*pow(x,2);
}

float df(float x, float a, float b){
    return a*exp(a*x) - 2*b*x;
}

float bisection(float xmin, float xmax, float a, float b, float acc){
    float xinc = 0.001;
    float xm;
    for(float x=xmin; x<=xmax; x+=xinc){
        if(f(x, a, b)*f(x+xinc, a, b) < 0){ 
            // root lies in bw x & x+xinc
            float xl = x, xr = x+xinc, z;
            do {
                xm = (xl+xr)/2;
                if(f(xm, a, b) * f(xl, a, b) > 0){
                    xl = xm;
                } else if(f(xm, a,b)* f(xl, a, b) < 0){
                    xr = xm;
                }
                z = (xl - xr)/(xl + xr);
            } while(fabs(z) > acc);
        }
    }
    return xm;
}
float secant(float xmin, float xmax, float a, float b, float acc){
    float x1 = xmin , x2 = xmax,x3, z;
    do {
        x3 = (x1 * f(x2, a,b) - x2*f(x1,a,b))/(f(x2,a,b) - f(x1,a,b));
        x1 = x2;
        x2 = x3;
        z = fabs(x1-x2);
    } while(z > acc);
    return x3;
}
float newtonraph(float x0, float a, float b, float acc){
    float locx = x0, f1, f2, h, z;
    do {
        f1 = f(locx, a,b);
        f2 = df(locx, a,b);
        h = -f1/f2;
        locx += h;
     } while((h/locx) > acc);
     return locx;
}

int main(){

    float a1 =1, b1 = 5;
    float a2 = -1.5, b2 = 10;

    printf("i)\nbisec=%f\n", bisection(-1, 1, a1, b1, 0.0000001));
    printf("secant=%f\n", secant(-1, 1, a1, b1, 0.0000001));
    printf("newtonraph=%f\n\n", newtonraph(0.6, a1, b1, 0.0000001));
    printf("ii)\nbisec=%f\n", bisection(-1, 1, a2, b2, 0.0000001));
    printf("secant=%f\n", secant(-1, 1, a2, b2, 0.0000001));
    printf("newtonraph=%f\n", newtonraph(0.2, a2, b2, 0.0000001));
}