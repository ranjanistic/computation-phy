#include<stdio.h>
#include<math.h>

float f(float x){
    return sin(x) - x*cos(x);
}

int main(){

    int a = 0;
    int b = 10;
    float acc = 0.0000001;
    float prevx = a - 1; // to ensure initial prevx value not in between a & b; 
    float prevfx;
    int n = 0; // will store no. of roots
    for(float x = a; x < b; x+=0.1){
        if(x != prevx){ // if different x value than the previous x
            if(f(x) * f(prevx) < 0){ // if sign changed from previous x and current x
                // now bisection b/w prevx and x (the current x);
                float x1 = prevx;
                float x2 = x;
                float xl = x1, xr = x2, xm, z;
                do{
                    xm = (xl + xr)/2;

                    if(f(xm) * f(xl) > 0){
                        xl = xm;
                    } else if(f(xm) * f(xl) < 0){
                        xr = xm;
                    }
                    z = fabs((xl - xr)/(xl + xr));
                } while (z > acc);
                printf("\nroot=%f, prevx(or xl, or x1)=%f, x(or xr, or x2)=%f, f(xm)=%f\n", xm, prevx, x, f(xm));
                n++;
            }
        }
        prevx = x;
        prevfx = f(x);
    }
    printf("\nTotal no. of roots between a & b: %d\n", n);
    return 0;
}