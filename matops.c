#include<stdlib.h>

float** matcreate(int rows, int cols) {
    float **mat = (float **)malloc(rows * sizeof(float *));
    for(int i = 0; i < rows; i++) {
        mat[i] = (float *)malloc(cols * sizeof(float));
    }
    return mat;
}

void matprint(float **a, int m, int n) {
    for(int i = 0; i < m; i++) {
        printf("[");
        for (int j = 0; j < n; j++) {
            printf(" %f ", a[i][j]);
        }
        printf("]\n");
    }
}

float** matadd(float **a, float **b, float **c, int m, int n){
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
   }

void matsub(float **a, float **b, float **c, int m, int n){
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}
void mattrans(float **a, float **c, int m, int n){
    
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            c[j][i] = a[i][j];
        }
    }
}

void matmul(float **a, float **b, float **c, int l, int m, int n){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < n; j ++){
            c[i][j] = 0;
            for(int k = 0; k < m; k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

