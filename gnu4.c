#include<stdio.h>
#include<math.h>

#define pi 3.14159


float orb(float th, int l, int m){
    if(l == 3){
        switch(m){
            case 0 : return (3*sqrt(14)/4) * (5*pow(cos(th),3)/3 - cos(th));
            case -1:
            case 1 : return (sqrt(42)*sin(th)/8) * (5*pow(cos(th),2) - 1);
            case -2:
            case 2 : return (sqrt(105)*pow(sin(th),2)*cos(th)/4);
            case -3:
            case 3 : return (sqrt(70)*pow(sin(th),3)/8);
            default: return 0;
        }
    }
    return 0;
}

int main(){

    FILE *fp = NULL;
    fp = fopen("data/gnu4.dat", "w");
    int l = 3, m = 0;
    for(float th = 1/100; th < 2*pi; th+=(pi/100)){
        fprintf(fp, "%f\t%f\n", pow(orb(th,l, m),2)*cos(th), pow(orb(th,l, m),2)*sin(th));
    }

    return 0;
}