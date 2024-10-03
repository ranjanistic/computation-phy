#include<stdio.h>
#include<math.h>

float j(float x){
    int k = 1, n = 0;
    float s = 1, t = 1;
    do{
        t*=pow(x,2)/(4*k*(n+k));
        s+=t;
        k++;
    } while((t/s) > 0.0001);
    return s;
}

int main(){

    float inc = 0.5;
    float xm, xl, xr,z;
    for(float x = 0.01; x <= 4; x+=inc){
    
        if(j(x)*j(x+inc) < 0){
            xl = x, xr = x +inc;
            do {
                xm = (xl + xr)/2;
                if(j(xm) * j(xl) > 0){
                    xl  = xm;
                } else if(j(xm) * j(xl) < 0){
                    xr = xm;
                }
                z = (xl - xr)/(xl + xr);
            } while(z > 0.00001);
        }
        printf("x=%f\tbessel root=%f\t%f\t%f\n",x, xm, j(x), j(xm));
    }

    return 0;
}