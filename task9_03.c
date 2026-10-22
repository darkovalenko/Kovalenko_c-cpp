#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double *inputVector(int n) {
    double *v;
    int i;
    v = (double *)malloc(n * sizeof(double));
    if (v == NULL) {
        return NULL;
    }
    for (i = 0; i < n; i++) {
        printf("v[%d]=", i);
        if (scanf("%lf", &v[i]) != 1) {
            free(v);
            return NULL;
        }
    }
    return v;
}

void freeVector(double *v) {
    free(v);
}

double *subtractVectors(double *a, double *b, int n) {
    double *c;
    int i;
    c = (double *)malloc(n * sizeof(double));
    if (c == NULL) {
        return NULL;
    }
    for (i = 0; i < n; i++) {
        c[i] = a[i] - b[i];
    }
    return c;
}

int main() {
    double *a = NULL, *b = NULL, *c = NULL;
    int n1, n2, i;
    setlocale(LC_ALL, "ukr");
    printf("Розмірність першого вектора n1=");
    if (scanf("%d", &n1) != 1 || n1 <= 0) {
        printf("Некоректна розмірність\n");
        return 1;
    }
    printf("Перший вектор\n");
    a = inputVector(n1);
    if (a == NULL) {
        printf("Помилка створення першого вектора\n");
        return 1;
    }
    printf("Розмірність другого вектора n2=");
    if (scanf("%d", &n2) != 1 || n2 <= 0) {
        printf("Некоректна розмірність\n");
        freeVector(a);
        return 1;
    }
    printf("Другий вектор\n");
    b = inputVector(n2);
    if (b == NULL) {
        printf("Помилка створення другого вектора\n");
        freeVector(a);
        return 1;
    }
    if (n1 != n2) {
        printf("Різниця неможлива: розмірності не збігаються\n");
    } else {
        c = subtractVectors(a, b, n1);
        if (c == NULL) {
            printf("Не вдалося виділити пам'ять\n");
        } else {
            printf("Різниця: (");
            for (i = 0; i < n1; i++) {
                printf("%g", c[i]);
                if (i < n1 - 1) {
                    printf("; ");
                }
            }
            printf(")\n");
            freeVector(c);
        }
    }
    freeVector(a);
    freeVector(b);
    return 0;
}
