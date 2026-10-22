#include <stdio.h>
#include <locale.h>

#define NMAX 100

double sumDiagonal(double a[NMAX][NMAX], int n, int m, int k) {
    int i, j;
    double s = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (i - j == k) {
                s = s + a[i][j];
            }
        }
    }
    return s;
}

int main() {
    static double a[NMAX][NMAX];
    int n, m, k, i, j;
    setlocale(LC_ALL, "ukr");
    printf("N=");
    scanf("%d", &n);
    printf("M=");
    scanf("%d", &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("a[%d][%d]=", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    printf("k=");
    scanf("%d", &k);
    printf("Сума елементів, для яких i-j=%d: %g\n", k, sumDiagonal(a, n, m, k));
    return 0;
}
