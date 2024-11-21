#include<stdio.h>
#include<math.h>


/*
dy/dx = x + y = y'
x = 0
y(0) = 1

sol.
y = 2exp(x) - x - 1
*/

float y(float x){
    return 2*exp(x) - x - 1;
}

float dy_dx(float x, float y){
    return x + y;
}


int main(){
    FILE *fpa = NULL, *fpe= NULL, *fprk= NULL;

    fpa = fopen("data/diff1a.dat", "w");
    fpe = fopen("data/diff1e.dat", "w");
    fprk = fopen("data/diff1rk.dat", "w");

    float y0 = 1, x0 = 0, xf = 5, h = 0.02;

    // analytical
    for(float locx = h; locx < 5; locx+=0.1){
        float locy = y(locx);
        fprintf(fpa, "%f\t%f\n", locx, locy); 
    }


    //euler's method
    float locx = x0, locy = y0;
    do{
        locy += h*dy_dx(locx, locy);
        locx += h;
        fprintf(fpe, "%f\t%f\n", locx, locy);
    } while (locx < xf);

    // rk4 method
    locx = x0, locy = y0;
    float k1, k2, k3, k4;
    do {
        k1 = h*dy_dx(locx, locy);
        k2 = h*dy_dx(locx + h/2, locy + k1/2);
        k3 = h*dy_dx(locx + h/2, locy + k2/2);
        k4 = h*dy_dx(locx + h, locy + k3);
        locx += h;
        locy += (k1 + 2*k2 + 2*k3 + k4)/6;
        fprintf(fprk, "%f\t%f\n", locx, locy);
    } while(locx < xf);

    fclose(fpa);
    fclose(fpe);
    fclose(fprk);

    return 0;
}