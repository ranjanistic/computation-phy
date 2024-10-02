#include<stdio.h>
#include<math.h>

#define pi 3.14159

float j(int n, float x, float acc){
    float s = 0, t = 1, k = 0;
    do{
        t*=-(pow(x,2)/4)/(k+1)*(n+k+1);
        s+=t;
        k++;
    } while(fabs(t/s) > acc);

    return pow((x/2), n) * s;
}


int main(){
    FILE *fp = fopen("data/series3.dat", "w");
        for(float x = 0; x <= 10; x+=0.01){
            fprintf(fp, "%f\t%f\t%f\t%f\n", x, j(0, x, 0.001),j(1, x, 0.001),j(2, x, 0.001));
        }
    
    return 0;
}