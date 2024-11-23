#include<stdio.h>
#include<math.h>


/*

x(n+1) = ax(n) - ax(n)x(n)

x = [0, 1]
x0 = 0.1  !(0, 1, 0.5)
a = [0, 4]


 */


int main(){

float x, i;
FILE *fp= NULL;
fp = fopen("data/diff6.dat", "w");
    for(float a = 0.01; a < 4; a+=0.05){
        x = 0.9;
        i = 0;
        do {
            x = a*x - a*x*x;
            i++;
            if(i > 10000){
                fprintf(fp, "%f\t%f\t%d\n", a, x, i);
            }
        } while( i <= (10000 + 100));
    }
}