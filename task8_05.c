#include <stdio.h>
#include <locale.h>

#define NMAX 20

void transpose(double a[NMAX][NMAX], int n) {
    int i, j;
    double tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    }
}

void printMatrix(double a[NMAX][NMAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%g", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double a[NMAX][NMAX];
    int n, i, j;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d]=", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    printf("Початкова матриця\n");
    printMatrix(a, n);
    transpose(a, n);
    printf("Транспонована матриця\n");
    printMatrix(a, n);
    return 0;
}
