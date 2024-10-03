#include <stdio.h>
#include <math.h>

#define pi 3.14159

float x(float th)
{
    return sin(th);
}

float y(float th, float A, int n, float del)
{
    return A * sin((n * th) + del);
}

int main()
{

    float del1 = pi/4;
    float A1 = 1, n11 = 1, n12 = 2, n13 = 2.5, n14 = 3;

    float del2 = pi/4;
    float n2 = 2, A21 = 0.5, A22 = 1, A23 = 2;

    float del31 = pi/4;
    float del32 = pi/2;
    float del33 = pi;
    float n3 = 2, A3 = 1;

    FILE *fpa1, *fpa2, *fpa3, *fpa4, *fpb1,*fpb2,*fpb3, *fpc1, *fpc2, *fpc3;

    fpa1 = fopen("data/gnu2a1.dat", "w");
    fpa2 = fopen("data/gnu2a2.dat", "w");
    fpa3 = fopen("data/gnu2a3.dat", "w");
    fpa4 = fopen("data/gnu2a4.dat", "w");

    fpb1 = fopen("data/gnu2b1.dat", "w");
    fpb2 = fopen("data/gnu2b2.dat", "w");
    fpb3 = fopen("data/gnu2b3.dat", "w");
    fpc1= fopen("data/gnu2c1.dat", "w");
    fpc2= fopen("data/gnu2c2.dat", "w");
    fpc3= fopen("data/gnu2c3.dat", "w");
    
    for(float th = 0; th <= 4 * pi; th+=pi/1000.0){
        fprintf(fpa1, "%f\t%f\t%f\n", th, x(th), y(th, A1, n11, del1));
        fprintf(fpa2, "%f\t%f\t%f\n", th, x(th), y(th, A1, n12, del1));
        fprintf(fpa3, "%f\t%f\t%f\n", th, x(th), y(th, A1, n13, del1));
        fprintf(fpa4, "%f\t%f\t%f\n", th, x(th), y(th, A1, n14, del1));
        fprintf(fpb1, "%f\t%f\t%f\n", th, x(th), y(th, A21, n2, del2));
        fprintf(fpb2, "%f\t%f\t%f\n", th, x(th), y(th, A22, n2, del2));
        fprintf(fpb3, "%f\t%f\t%f\n", th, x(th), y(th, A23, n2, del2));
        fprintf(fpc1, "%f\t%f\t%f\n", th, x(th), y(th, A3, n3, del31));
        fprintf(fpc2, "%f\t%f\t%f\n", th, x(th), y(th, A3, n3, del32));
        fprintf(fpc3, "%f\t%f\t%f\n", th, x(th), y(th, A3, n3, del33));
    }
    
    fclose(fpa1);
    fclose(fpa2);
    fclose(fpa3);
    fclose(fpa4);
    fclose(fpb1);
    fclose(fpb2);
    fclose(fpb3);
    fclose(fpc1);
    fclose(fpc2);
    fclose(fpc3);
    return 0;
}