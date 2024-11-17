#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159

int main(){
    FILE *fp = fopen("data/intro3.dat","w");
    for(int a = 1; a <= 100; a+=1){
        for(int b = a+1; b <= 100; b+=1){
            float res = sqrt(pow(a, 2) + pow(b, 2));
            if(res > 100){
                break;
            }
            if(((int) res) == res){
                fprintf(fp, "%d,%d,%d\n", a, b, (int) res);
            }
        }
    }
    fclose(fp);
    return 0;
}