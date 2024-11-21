#include<stdio.h>
#include<math.h>


/*
dx/dt = -10(x-y)
dy/dt = ax - xz - y
dz/dt = xy - 8z/3


*/


#define x_(t, x, y, z) ((-10 * ((x) - (y)))) 
#define y_(t, x, y, z) ((a)*(x) - (x)*(z) - (y)) 
#define z_(t, x, y, z) ((x)*(y) - 8*(z)/(3))


int main(){

    float h = 0.01;
    float loct = 0, locx = 1, locy = 2, locz = 1;
    double k[4], m[4], n[4];
    float a = 5;
    FILE *fp = NULL;
    fp = fopen("data/diff5.dat", "w");
    
    do {
        k[0] = h*x_(loct, locx, locy, locz);
        m[0] = h*y_(loct, locx, locy, locz);
        n[0] = h*z_(loct, locx, locy, locz);
        k[1] = h*x_(loct + h/2, locx + k[0]/2, locy + k[0]/2, locz + k[0]/2);
        m[1] = h*y_(loct + h/2, locx + m[0]/2, locy + m[0]/2, locz + m[0]/2);
        n[1] = h*z_(loct + h/2, locx + n[0]/2, locy + n[0]/2, locz + n[0]/2);
        k[2] = h*x_(loct + h/2, locx + k[1]/2, locy + k[1]/2, locz + k[1]/2);
        m[2] = h*y_(loct + h/2, locx + m[1]/2, locy + m[1]/2, locz + m[1]/2);
        n[2] = h*z_(loct + h/2, locx + n[1]/2, locy + n[1]/2, locz + n[1]/2);
        k[3] = h*x_(loct + h, locx + k[2], locy + k[2], locz + k[2]);
        m[3] = h*y_(loct + h, locx + m[2], locy + m[2], locz + m[2]);
        n[3] = h*z_(loct + h, locx + n[2], locy + n[2], locz + n[2]);

        loct += h;
        locx += (k[0] + k[3] + 2*(k[1]+k[2]))/6;
        locy += (m[0] + m[3] + 2*(m[1]+m[2]))/6;
        locz += (n[0] + n[3] + 2*(n[1]+n[2]))/6;

        fprintf(fp, "%f\t%f\t%f\t%f\n", loct, locx, locy, locz);
    } while(loct < 20);

    fclose(fp);
    return 0;
}