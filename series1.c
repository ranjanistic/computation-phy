#include<stdio.h>
#include<math.h>


int main(){
    float terms = 20;
    for(int x = 1; x <= 5; x++){  
        float sum = 0;
        float t = 1;
        for(int term = 1; term <= terms; term++){
            if(term == 1){
                sum += 1;
            } else {
                t*=1/pow(x, term);
                sum+=t;
            }
        }
       printf("x=%d,Sum=%f\t", x, sum);
    }
}