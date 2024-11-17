#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159


void plot(){
    FILE *fp2 = fopen("plots/gnuia.p", "w");
    fprintf(fp2, "set terminal postscript enhanced color solid 22\n");
    fprintf(fp2, "set output 'gnuia.eps'\n");
    fprintf(fp2, "set title \"GNU IA ques\"\n");
    fprintf(fp2, "set grid\n");
    fprintf(fp2, "set xrange [-6*pi:6*pi]\n");
    fprintf(fp2, "set xtics (-6*pi,-5*pi,-4*pi,-3*pi,-2*pi,-pi,0,pi,2*pi,3*pi,4*pi,5*pi,6*pi)\n");
    fprintf(fp2, "plot \"gnuia.dat\" u 1:2 w linespoints, \"gnuia.dat\" u 1:3 w linespoints");
    fclose(fp2);
}

float triangle(float x, float amplitude, float width) {   
    if (0 <= x && x < amplitude) {
        return x;
    }
    if (amplitude <= x  && x < width) {
        return width - x;
    }
    return x;
}

float line(float x, float amplitude, float width) {   
    if(width/2 < x  && x < 3*width/2){
        return amplitude;
    }
    return 0;
}

int main() {
    float period = 2*PI;
    float period2 = PI;
    float start = -6*PI;
    float end = 6*PI;

    FILE *fp = fopen("data/gnuia.dat", "w");

    for (float x = start; x <= end; x += (period / 1000)) {
        float locx =  fabs(x) - (period*(int)fabs((x/period)));
        if(x < 0){
            locx = period - locx;
        }
        float ty = triangle(locx, period/2, period);
        float ly = line(locx, period2/2, period2);
        if(ly == 0){
            fprintf(fp, "%f\t%f\t\n", x, ty);
        } else {
            fprintf(fp, "%f\t%f\t%f\n", x, ty, ly);
        }
    }

    fclose(fp);
    plot();
    return 0;
}
