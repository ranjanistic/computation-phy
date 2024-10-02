#include<stdio.h>
#include<math.h>


int main(){
    float terms = 3;
    for(float x = 0.2; x <= 2.1; x+=0.1){  
        float sum = 0;
        float t = 1;
        for(int term = 1; term <= terms; term++){
            if(term == 1){
                sum += 1;
            } else {
                t*=1/pow(x, 1);
                sum+=t;
            }
        }
       printf("x=%f,Sum=%f\n", x, sum);
    }
}