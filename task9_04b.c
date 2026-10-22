#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double *createMatrix(int n) {
    return (double *)calloc((size_t)n * n, sizeof(double));
}

void freeMatrix(double *a) {
    free(a);
}

double *inputMatrix(int n) {
    double *a;
    int i, j;
    a = createMatrix(n);
    if (a == NULL) {
        return NULL;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d]=", i, j);
            if (scanf("%lf", &a[i * n + j]) != 1) {
                freeMatrix(a);
                return NULL;
            }
        }
    }
    return a;
}

void printMatrix(double *a, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%g", a[i * n + j]);
        }
        printf("\n");
    }
}

double *multiplyMatrices(double *a, double *b, int n) {
    double *c;
    int i, j, k;
    c = createMatrix(n);
    if (c == NULL) {
        return NULL;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                c[i * n + j] = c[i * n + j] + a[i * n + k] * b[k * n + j];
            }
        }
    }
    return c;
}

int main() {
    double *a, *b, *c;
    int n1, n2;
    setlocale(LC_ALL, "ukr");
    printf("Порядок першої матриці n1=");
    if (scanf("%d", &n1) != 1 || n1 <= 0) {
        printf("Некоректний порядок\n");
        return 1;
    }
    printf("Перша матриця\n");
    a = inputMatrix(n1);
    if (a == NULL) {
        printf("Помилка створення першої матриці\n");
        return 1;
    }
    printf("Порядок другої матриці n2=");
    if (scanf("%d", &n2) != 1 || n2 <= 0) {
        printf("Некоректний порядок\n");
        freeMatrix(a);
        return 1;
    }
    printf("Друга матриця\n");
    b = inputMatrix(n2);
    if (b == NULL) {
        printf("Помилка створення другої матриці\n");
        freeMatrix(a);
        return 1;
    }
    if (n1 != n2) {
        printf("Добуток неможливий: порядки матриць не збігаються\n");
    } else {
        c = multiplyMatrices(a, b, n1);
        if (c == NULL) {
            printf("Не вдалося виділити пам'ять\n");
        } else {
            printf("Добуток\n");
            printMatrix(c, n1);
            freeMatrix(c);
        }
    }
    freeMatrix(a);
    freeMatrix(b);
    return 0;
}
