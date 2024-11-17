#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159

float f(float x, float y){
    float absx = abs(x), absy = abs(y);
    if(absx > absy){
        return pow(absx,2)+ pow(absy, 4);
    } else if(absx == absy) {
        return pow(absx,2) * (pow(absx,2) + 1);
    } else if (absx < absy){
        return pow(absy,2) + pow(absx, 4);
    }
    return 0;
}

int main(){
    FILE *fp = fopen("data/intro2.dat","w");
    for(float x = 0, y = 0; x <= 1; x +=0.25, y+=0.25){
        fprintf(fp, "%f\t%f\t%f\n", x, y, f(x,y));
    }
    fclose(fp);
    return 0;
}