#include<stdio.h>
#include<math.h>


/*
 th'' = -sin(th)

 t = 0
 th(0) = a
 th'(0) = 0

*/

#define pi 3.14159
#define dv_dt(t, th, v) (( - sin(th) ))
#define dth_dt(t, th, v) (( v ))

int main(){

    FILE *fp = NULL;
    fp = fopen("data/diff2.dat", "w");
    float h = 0.01;
    for(float a = 0.1; a <= 1.1; a+=0.1){
        if((fabs(a - 0.1) < 0.0001) || (fabs(a - 0.5) < 0.0001) || (fabs(a - 1.0) < 0.0001)){    
    
            float loct = 0, locth = a, locv = 0;
            float k1, k2, k3, k4, m1, m2, m3, m4;
            do {
                k1 = h*dth_dt(loct, locth, locv);
                m1 = h*dv_dt(loct, locth, locv);
                k2 = h*dth_dt(loct + h/2, locth + k1/2, locv + m1/2);
                m2 = h*dv_dt(loct + h/2, locth + k1/2, locv + m1/2);
                k3 = h*dth_dt(loct + h/2, locth + k2/2, locv + m2/2);
                m3 = h*dv_dt(loct + h/2, locth + k2/2, locv + m2/2);
                k4 = h*dth_dt(loct + h, locth + k3, locv + m3);
                m4 = h*dth_dt(loct + h, locth + k3, locv + m3);
                
                loct += h;
                locth += (k1 + 2*k2 + 2*k3 + k4)/6;
                locv += (m1 + 2*m2 + 2*m3 + m4)/6;
                printf("%f\n",a);
                    fprintf(fp, "%f\t%f\t%f\n", loct, locth, a*cos(locth*loct));

            } while (loct <= 1);
        }
    }

    fclose(fp);
    return 0;
}