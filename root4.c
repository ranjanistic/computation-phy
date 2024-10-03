#include<stdio.h>
#include<math.h>

#define pi 3.14159

float f(float x, float eps, float t, float w){
    return x - eps*sin(x) - w*t;
}

float df_x(float x, float eps){
    return 1 - eps*cos(x);
}


int main(){
    FILE *fp = fopen("data/root4.dat", "w");
    float x, eps = 0.8, w = 1, a = 2.0;
    float r, costh, sinth;
    float x1, y1;
    for(float t = 0.00001; t < (2*pi); t+=0.05){
        x = t;
        float f1, f2, h;
        do{
            f1 = f(x, eps, t, w);
            f2 = df_x(x, eps);

            h = -f1/f2;
            x+=h;
        } while(fabs(h/x) > 0.00001);

        printf("t=%f\troot=%f\n", t,x);
        r = a *(1 - eps*cos(x));
        costh = (cos(x) - eps)/(1 - eps*cos(x));
        sinth = sqrt(1 - pow(costh,2));
        x1 = r*costh;
        y1 = r*sinth;
        fprintf(fp, "%f\t%f\n", x1, y1);
        fprintf(fp, "%f\t%f\n", x1, -y1);
    }   

    fclose(fp);
}