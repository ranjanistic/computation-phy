#include<stdio.h>
#include<math.h>

#define size 3

void matprint(float a[size][size]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%2.1f  ", a[i][j]);
        }
        printf("\n");
    }
}

void matprint2x2(float a[2][2]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%2.1f ", a[i][j]);
        }
        printf("\n");
    }
}

void transpose(float a[size][size]){
    float b[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
           b[j][i]  = a[i][j];
        }
    } 
    matprint(b);
}


float trace(float a[size][size], int m, int n){
    if(m != n){
        printf("Only square matrices have trace.");
        return 0;
    }
    float sum = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(i == j){
                sum += a[i][j];
            }
        }
    }
    return sum;
}

float determinant3x3(float a[size][size]){
    float det = 0;
    for(int j = 0; j < size; j++){
        float suba[2][2];

        int ci = 0;
        for(int ji = 1; ji < size; ji++){
            int cj = 0;
            for (int jj = 0; jj < size; jj++){
                if(jj != j){
                    suba[ci][cj] = a[ji][jj];
                    cj++;
                }
            } 
            ci++;
        }  

        float cf = pow(-1, 0+j) * (suba[0][0] * suba[1][1] - suba[0][1]*suba[1][0]);

        det +=  a[0][j] * cf;
    }
    return det;
}


void cfmatrix3x3(float a[size][size]){
    float cfm[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            float suba[2][2];
            int ci = 0;
            for(int ji = 0; ji < size; ji++){
                int cj = 0;
                if(ji != i){
                    for (int jj = 0; jj < size; jj++){
                        if(jj != j){
                            suba[ci][cj] = a[ji][jj];
                            cj++;
                        }
                    } 
                    ci++;
                }
            }  
            float cf = pow(-1, i+j) * (suba[0][0] * suba[1][1] - suba[0][1]*suba[1][0]);
            cfm[i][j] = cf;
        }
    }
    matprint(cfm);
}

float adjoint3x3(float a[size][size]){

    float adj[size][size];
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            float suba[2][2];
            int ci = 0;
            for(int ji = 0; ji < size; ji++){
                int cj = 0;
                if(ji != i){
                    for (int jj = 0; jj < size; jj++){
                        if(jj != j){
                            suba[ci][cj] = a[ji][jj];
                            cj++;
                        }
                    } 
                    ci++;
                }
            }  
            float cf = pow(-1, i+j) * (suba[0][0] * suba[1][1] - suba[0][1]*suba[1][0]);
            adj[j][i] = cf;
        }
    }
    matprint(adj);
}

float inverse3x3(float a[size][size]){
    float det = determinant3x3(a);

    float inv[size][size];
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            float suba[2][2];
            int ci = 0;
            for(int ji = 0; ji < size; ji++){
                int cj = 0;
                if(ji != i){
                    for (int jj = 0; jj < size; jj++){
                        if(jj != j){
                            suba[ci][cj] = a[ji][jj];
                            cj++;
                        }
                    } 
                    ci++;
                }
            }  
            float cf = pow(-1, i+j) * (suba[0][0] * suba[1][1] - suba[0][1]*suba[1][0]);
            inv[j][i] = cf/det;
        }
    }
    matprint(inv);
}


int main(){


    float a[size][size] = {
        {2, 2, 3},
        {2, 5, 6},
        {2, 5, 5},
    };
    matprint(a);
    printf("\ntrace: %2.1f\n", trace(a ,size, size));
    printf("\ndet: %2.1f\n", determinant3x3(a));
    printf("\ncfmatrix\n");
    cfmatrix3x3(a);
    printf("\ntransp\n");
    transpose(a);
    printf("\nadjoint\n");
    adjoint3x3(a);
    printf("\ninverse\n");
    inverse3x3(a);
    printf("\n\n");
    return 0;
}