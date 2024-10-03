#include<stdio.h>
#include<math.h>

#define pi 3.14159

int fact(int n){
    if(n == 0) return 1;
    int i = n;
    while((i - 1) > 0){
        i*=(i - 1);
        i--;
    }
    return i;
}

float j(int n, float x, float acc){
    float s = 1/fact(n), t = 1, k = 1;
    do{
        t*=-(pow(x,2)/4)/((k)*(n+k));
        s+=t;
        k++;
    } while(fabs(t/s) > acc);

    return pow((x/2), n) * s;
}


int main(){
    FILE *fp = fopen("data/series3.dat", "w");
    for(float x = 0; x <= 16; x+=0.01){
        fprintf(fp, "%f\t%f\t%f\t%f\n", x, j(0, x, 0.001),j(1, x, 0.001),j(2, x, 0.001));
    }
    fclose(fp);
    
    return 0;
}

