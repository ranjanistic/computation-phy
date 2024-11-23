#include<stdio.h>
#include<math.h>


void matprint(float a[2][3], int m, int n){

    for(int i = 0; i < m; i++){
        printf("[");
        for (int j = 0; j < n; j++){
            printf(" %f ", a[i][j]);
        }
        printf("]\n");
    }
}

void matprint2(float a[3][2], int m, int n){

    for(int i = 0; i < m; i++){
        printf("[");
        for (int j = 0; j < n; j++){
            printf(" %f ", a[i][j]);
        }
        printf("]\n");
    }
}
void matprint3(float a[2][2], int m, int n){

    for(int i = 0; i < m; i++){
        printf("[");
        for (int j = 0; j < n; j++){
            printf(" %f ", a[i][j]);
        }
        printf("]\n");
    }
}

float matadd(float a[2][3], float b[2][3], int m, int n){
    float c[m][n];
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    matprint(c, m, n);
}

float matsub(float a[2][3], float b[2][3], int m, int n){
    float c[m][n];
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    matprint(c, m, n);
}
float mattrans(float a[2][3], int m, int n){
    float c[n][m];
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            c[j][i] = a[i][j];
        }
    }
    matprint2(c, n, m);
}

float matmul(float a[2][3], float b[3][2], int l, int m, int n){
    float c[l][n];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < n; j ++){
            c[i][j] = 0;
            for(int k = 0; k <= m; k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    matprint3(c, l, n);
}


int main(){
    int m = 2, n = 3;
    float a[2][3] = {{ 1, 3, 4}, {5, 6, 7}};
    float b[2][3] = {{ 9, 1, 2}, {2, 4, 5}};
    float c[3][2] = {{ 9, 1}, {2, 4}, {3, 6}};
    
    printf("\na\n");
    matprint(a, m, n);
    printf("\nc\n");
    matprint2(c, n, m);
    printf("\ntrans a\n");
    mattrans(a, m, n);
    printf("\nb\n");
    matprint(b, m, n);
    printf("\ntrans b\n");
    mattrans(b, m, n);
    printf("\nadd\n");
    matadd(a, b, m, n);
    printf("\na - b\n");
    matsub(a, b, m, n);
    printf("\nb - a\n");
    matsub(b, a, m, n);
    printf("\na x c\n");
    matmul(a, c, 2, 3, 2);
    return 0;
}