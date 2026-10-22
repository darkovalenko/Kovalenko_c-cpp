#include <stdio.h>
#include <math.h>
#include <locale.h>

#define NMAX 100

int inputArray(int a[], int *n) {
    int x;
    *n = 0;
    while (*n < NMAX) {
        printf("a[%d]=", *n);
        if (scanf("%d", &x) != 1) {
            return 0;
        }
        if (x == 0) {
            break;
        }
        a[*n] = x;
        (*n)++;
    }
    return 1;
}

int isSquare(int x) {
    long long r;
    if (x < 0) {
        return 0;
    }
    r = (long long)(sqrt((double)x) + 0.5);
    return r * r == x;
}

int isCube(int x) {
    long long r;
    double v = fabs((double)x);
    r = (long long)(cbrt(v) + 0.5);
    return r * r * r == (long long)v;
}

int main() {
    int a[NMAX];
    int n, i, squares = 0, cubes = 0;
    setlocale(LC_ALL, "ukr");
    if (!inputArray(a, &n)) {
        printf("Некоректне введення\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        if (isSquare(a[i])) {
            squares++;
        }
        if (isCube(a[i])) {
            cubes++;
        }
    }
    printf("Кількість елементів: %d\n", n);
    printf("Повних квадратів: %d\n", squares);
    printf("Повних кубів: %d\n", cubes);
    return 0;
}
