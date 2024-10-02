#include<stdio.h>
#include<math.h>


int main(){

    FILE *fp = NULL;
    fp = fopen("gnu1c.txt", "w");

    float x, y;
    for(x = 1; x <= 5;x+=0.1){
        y = 1;
        fprintf(fp, "%f\t%f\n", x, y);
    }
    for(x = 5; x >= 1;x-=0.1){
        y = 5;
        fprintf(fp, "%f\t%f\n", x, y);
    }
    for(y = 1; y <= 5;y+=0.1){
        x = 5;
        fprintf(fp, "%f\t%f\n", x, y);
    }
    for(y = 5; y >= 1;y-=0.1){
        x = 1;
        fprintf(fp, "%f\t%f\n", x, y);
    }
    return 0;
}