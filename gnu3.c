#include <stdio.h>
#include <math.h>

#define pi 3.14159

float y(float x) {
    if (0 <= x && x < pi) {
        return x;
    }
    if (pi <= x && x < 2 * pi) {
        return 2 * pi - x;
    }
    return 0;
}

int main() {

    float y(float x);
    
    FILE *fp;
    float period = 2*pi;


    fp = fopen("data/gnu3.dat", "w");

    for (float x = -6*pi; x <= 6*pi; x+= pi/1000.0) {
        fprintf(fp, "%f\t%f\n", x, y(fabs(x - (period * (int)(x/period)))));
    }
    return 0;
}