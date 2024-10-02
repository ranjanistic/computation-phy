#include <stdio.h>
#include <math.h>

int main(){
    float x, y, r, t, x0;

    FILE *fp;
    fp = fopen("gnu1a.txt", "w");

    for (x = 0; x <= 4; x += 0.1){
        y = 0;
        fprintf(fp, "%f\t%f\n", x, y);
    }

    for (y = 0; y < 3; y += 0.1){
        x = 4;
        fprintf(fp, "%f\t%f\n", x, y);
    }
 
    for (x = 0; x < 4; x += 0.1){
        y = (3 / 4) * x;
        fprintf(fp, "%f\t%f\n", x, y);
    }
    return 0;   
}
