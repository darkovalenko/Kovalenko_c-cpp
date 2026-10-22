#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <locale.h>

double **createMatrix(int n, int m) {
    double **a;
    int i, j;
    a = (double **)malloc(n * sizeof(double *));
    if (a == NULL) {
        return NULL;
    }
    for (i = 0; i < n; i++) {
        a[i] = (double *)calloc(m, sizeof(double));
        if (a[i] == NULL) {
            for (j = 0; j < i; j++) {
                free(a[j]);
            }
            free(a);
            return NULL;
        }
    }
    return a;
}

void freeMatrix(double **a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
}

void printMatrix(double **a, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("\t%.2f", a[i][j]);
        }
        printf("\n");
    }
}

void fillRandom(double **a, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = rand() % 2001 / 100.0 - 10;
        }
    }
}

int fillConsole(double **a, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("a[%d][%d]=", i, j);
            if (scanf("%lf", &a[i][j]) != 1) {
                return 0;
            }
        }
    }
    return 1;
}

double **addColumnsToBegin(double **a, int n, int m, int k) {
    double **b;
    int i, j;
    b = createMatrix(n, m + k);
    if (b == NULL) {
        return NULL;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            b[i][j + k] = a[i][j];
        }
    }
    return b;
}

int main() {
    double **a, **b;
    int n, m, k, mode;
    setlocale(LC_ALL, "ukr");
    srand((unsigned)time(NULL));
    printf("N=");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некоректне N\n");
        return 1;
    }
    printf("M=");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Некоректне M\n");
        return 1;
    }
    a = createMatrix(n, m);
    if (a == NULL) {
        printf("Не вдалося виділити пам'ять\n");
        return 1;
    }
    printf("Заповнення: 1 - випадкові числа, 2 - з консолі: ");
    if (scanf("%d", &mode) != 1 || (mode != 1 && mode != 2)) {
        printf("Некоректний вибір\n");
        freeMatrix(a, n);
        return 1;
    }
    if (mode == 1) {
        fillRandom(a, n, m);
    } else if (!fillConsole(a, n, m)) {
        printf("Некоректне введення\n");
        freeMatrix(a, n);
        return 1;
    }
    printf("Матриця\n");
    printMatrix(a, n, m);

    printf("k=");
    if (scanf("%d", &k) != 1 || k < 0 || k > INT_MAX - m) {
        printf("Некоректне k\n");
        freeMatrix(a, n);
        return 1;
    }
    if (k == 0) {
        printf("Нічого додавати\n");
        freeMatrix(a, n);
        return 0;
    }
    b = addColumnsToBegin(a, n, m, k);
    if (b == NULL) {
        printf("Не вдалося виділити пам'ять\n");
        freeMatrix(a, n);
        return 1;
    }
    freeMatrix(a, n);
    printf("Матриця після додавання %d стовпців на початок\n", k);
    printMatrix(b, n, m + k);
    freeMatrix(b, n);
    return 0;
}
