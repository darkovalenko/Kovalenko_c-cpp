#include <stdio.h>
#include <math.h>
#include <locale.h>

#define NMAX 20

double determinant(double a[NMAX][NMAX], int n) {
    int i, j, k, p;
    double det = 1, tmp, f;
    for (k = 0; k < n; k++) {
        p = k;
        for (i = k + 1; i < n; i++) {
            if (fabs(a[i][k]) > fabs(a[p][k])) {
                p = i;
            }
        }
        if (a[p][k] == 0) {
            return 0;
        }
        if (p != k) {
            for (j = 0; j < n; j++) {
                tmp = a[k][j];
                a[k][j] = a[p][j];
                a[p][j] = tmp;
            }
            det = -det;
        }
        det = det * a[k][k];
        for (i = k + 1; i < n; i++) {
            f = a[i][k] / a[k][k];
            for (j = k; j < n; j++) {
                a[i][j] = a[i][j] - f * a[k][j];
            }
        }
    }
    return det;
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
    printf("Детермінант = %g\n", determinant(a, n));
    return 0;
}
