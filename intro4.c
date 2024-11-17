#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159

int sumOfDigits(int number){
    int rem = number;
    int sum = 0;
    while(rem > 0){
        sum += (int)(rem%10);
        rem = (int)(rem/10);
    }
    return sum;
}

int main(){
    FILE *fp = fopen("data/intro4.dat","w");
    for(int x = 50; x <= 70; x+=1){
        if(x % sumOfDigits(x) == 0){
            fprintf(fp, "%d\n", x);
        }
    }
    fclose(fp);
    return 0;
}