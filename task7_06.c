#include <stdio.h>
#include <locale.h>

#define NMAX 20

void inputVector(int n, double a[]) {
    int i;
    for (i = 0; i < n; i++) {
        printf("a[%d]=", i);
        scanf("%lf", &a[i]);
    }
}

void printVector(int n, double a[]) {
    int i;
    printf("(");
    for (i = 0; i < n; i++) {
        printf("%g", a[i]);
        if (i < n - 1) {
            printf("; ");
        }
    }
    printf(")\n");
}

void sumVectors(int n, double a[], double b[], double c[]) {
    int i;
    for (i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
}

double scalarProduct(int n, double a[], double b[]) {
    int i;
    double s = 0;
    for (i = 0; i < n; i++) {
        s = s + a[i] * b[i];
    }
    return s;
}

int main() {
    double a[NMAX], b[NMAX], c[NMAX];
    int n;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%d", &n);
    printf("Перший вектор\n");
    inputVector(n, a);
    printf("Другий вектор\n");
    inputVector(n, b);
    sumVectors(n, a, b, c);
    printf("Сума: ");
    printVector(n, c);
    printf("Скалярний добуток: %f\n", scalarProduct(n, a, b));
    return 0;
}
