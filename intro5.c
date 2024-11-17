#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main() {
    FILE *fp = fopen("data/intro5.dat", "w");
    int x = 1;
    int t1 = 0, t2 = 1;
    int next = t1 + t2;
    while (next <= 200) {
        fprintf(fp, "%d\n", next);
        t1 = t2;
        t2 = next;
        next = t1 + t2;
    }
    fclose(fp);
    return 0;
}