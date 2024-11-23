#include<stdio.h>
#include<stdlib.h>
#include "matops.c"


int main(){
    int m = 4, n =4;
    
    float **a = matcreate(m,n);
    float **b = matcreate(m,n);
    float **c = matcreate(m,n);
    float **d = matcreate(m,n);
    float **e = matcreate(m,n);
    for(float i = 1; i <= m; i ++){
        for (float j = 1; j <= n; j++){
            // printf("%f\n", i);
            a[(int)i-1][(int)j-1] = (float)(i/(i +j));
            b[(int)i-1][(int)j-1] = (float)(j/(i +j));
            
        }
    }
    printf("\na\n");
    matprint(a, m, n); 
    
    printf("\nb\n");
    matprint(b, m, n); 
    matmul(a, b, c, m, m, n);
    printf("\na*b\n");
    matprint(c, m, n); 
    matmul(b, a, d, m, m, n);
    printf("\nb*a\n");
    matprint(d, m, n); 
    printf("\n[a,b] (commutator)\n");
    matsub(c, d, e, m, n);
    matprint(e, m, n);
    return 0; 
}