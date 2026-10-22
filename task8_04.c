#include <stdio.h>
#include <locale.h>

#define NMAX 25

void inputMatrixInt(int a[NMAX][NMAX], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        printf("Рядок %d: ", i);
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void inputMatrixDouble(double a[NMAX][NMAX], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        printf("Рядок %d: ", i);
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
}

int main() {
    int ai[NMAX][NMAX];
    double ad[NMAX][NMAX];
    int m, n, i, j;
    setlocale(LC_ALL, "ukr");
    printf("m=");
    scanf("%d", &m);
    printf("n=");
    scanf("%d", &n);
    printf("Цілі числа\n");
    inputMatrixInt(ai, m, n);
    printf("Дійсні числа\n");
    inputMatrixDouble(ad, m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%d", ai[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%g", ad[i][j]);
        }
        printf("\n");
    }
    return 0;
}
