#include<stdio.h>
#include<math.h>

#define pi 3.14159

int main(){
    FILE *fp = fopen("data/series6.dat", "w");
    float acc = 0.01;
    for(float z = -10; z <= 0; z+=0.05){
        float t = 1, s = 1, k = 1;

        do {
            t*=pow(z,3)/(3*k*(3*k - 1));
            s+=t;
            k+=1;
        } while(fabs(t/s)>acc);
        
        fprintf(fp, "%f\t%f\n", z, s);
    }
    fclose(fp);
    return 0;
}
