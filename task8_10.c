#include <stdio.h>
#include <locale.h>

#define NMAX 100

void rotate180(double a[NMAX][NMAX], int size) {
    int i, j;
    double tmp;
    for (i = 0; i < size / 2; i++) {
        for (j = 0; j < size; j++) {
            tmp = a[i][j];
            a[i][j] = a[size - 1 - i][size - 1 - j];
            a[size - 1 - i][size - 1 - j] = tmp;
        }
    }
}

int main() {
    static double a[NMAX][NMAX];
    int n, size, i, j;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%d", &n);
    size = 2 * n;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("a[%d][%d]=", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    rotate180(a, size);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("\t%g", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
