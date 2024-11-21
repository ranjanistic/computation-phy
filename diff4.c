#include<stdio.h>
#include<math.h>

/*
 f1 d2y/dx2 + f2 dy/dx + f3 y = f4

 x = 0
 y(x) = 0
 y'(x) = 1

 f1 = 1
 f2 = 1
 f3 = 4x

 dy/dx = y' = v
 => f1 dv/dx + f2 v + f3 y = f4
 => dv/dx = (f4 - (f3)y - f2v)/f1
 and
  dy/dx = v
*/

#define f2 1.0
#define f1 1.0
#define dy_dx(x, y, v) ((v))
#define dv_dx(x, y, v) (((f4((x))) - (f3((x)))*(y) - ((f2)))/((f1)))

float f4(float x){
    float t = 1, sum = 1;
    for(int i = 1; i <= 10; i++){
        t *= -pow(x,2)/((2*i+1)*2*i);
        sum+=t;
    }
    return sum;
}

float f3(float x){
    return 4*x;
}

int main(){

    float h = 0.001;
    float k1, k2, k3, k4;
    float m1, m2, m3, m4;
    FILE *fp = NULL;
    fp = fopen("data/diff4.dat", "w");
    float locx = 0, locy = 0, locv = 1;
    do {
        k1 = h*dy_dx(locx, locy, locv);
        m1 = h*dv_dx(locx, locy, locv);
        k2 = h*dy_dx(locx+ h/2, locy + k1/2, locv + m1/2);
        m2 = h*dv_dx(locx+ h/2, locy + k1/2, locv + m1/2);
        k3 = h*dy_dx(locx+ h/2, locy + k2/2, locv + m2/2);
        m3 = h*dv_dx(locx+ h/2, locy + k2/2, locv + m2/2);
        k4 = h*dy_dx(locx+ h, locy + k3, locv + m3);
        m4 = h*dv_dx(locx+ h, locy + k3, locv + m3);

        locx += h;
        locy += (k1 + k4 + 2*(k2 + k3))/6;
        locv += (m1 + m4 + 2*(m2 + m3))/6;
        fprintf(fp, "%f\t%f\n", locx, locy);
    } while (locx <= 1);

    fclose(fp);
    return 0;
}