#include<stdio.h>
#include<math.h>

/*
df_dt = af - bfy
dy_dt = -cy + dfy

*/

#define df_dt(t, f, y) (a*(f) - b*(f)*(y))
#define dy_dt(t, f, y) (-c*(y) + d*(f)*(y))


int main(){
    float h = 0.001;
    float a = 0.25, b = 0.01, c = 1, d = 0.01;
    float k1, k2, k3, k4;
    float m1, m2, m3, m4;
    FILE *fp = NULL;
    fp = fopen("data/diff3.dat", "w");
    for(float y0 = 5; y0 <= 25; y0 += 5){
        float loct = 0, locf = 100, locy = y0;
        do {
            k1 = h*df_dt(loct, locf, locy);
            m1 = h*dy_dt(loct, locf, locy);
            k2 = h*df_dt(loct + h/2, locf + k1/2, locy + m1/2);
            m2 = h*dy_dt(loct + h/2, locf + k1/2, locy + m1/2);
            k3 = h*df_dt(loct + h/2, locf + k2/2, locy + m2/2);
            m3 = h*dy_dt(loct + h/2, locf + k2/2, locy + m2/2);
            k4 = h*df_dt(loct + h, locf + k3, locy + m3);
            m4 = h*dy_dt(loct + h, locf + k3, locy + m3);
            
            locf += (k1 + 2*k2 + 2*k3 + k4)/6;
            locy += (m1 + 2*m2 + 2*m3 + m4)/6;
            loct += h;
            
            fprintf(fp, "%f\t%f\n", locf, locy);
        } while ( loct <= 20);
    }
    fclose(fp);
    return 0;
}