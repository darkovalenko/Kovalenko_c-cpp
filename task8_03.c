#include <stdio.h>
#include <locale.h>

#define NMAX 20

void inputMatrix(double a[NMAX][NMAX], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d]=", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
}

void printMatrix(double a[NMAX][NMAX], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%g", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double a[NMAX][NMAX];
    int m, n;
    setlocale(LC_ALL, "ukr");
    printf("m=");
    scanf("%d", &m);
    printf("n=");
    scanf("%d", &n);
    inputMatrix(a, m, n);
    printMatrix(a, m, n);
    return 0;
}
