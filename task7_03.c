#include <stdio.h>
#include <math.h>
#include <locale.h>

#define N 10

double sumGreaterE(double a[], int n) {
    double e = exp(1.0), s = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] > e) {
            s = s + a[i];
        }
    }
    return s;
}

int main() {
    double a[N];
    int i;
    setlocale(LC_ALL, "ukr");
    for (i = 0; i < N; i++) {
        printf("a[%d]=", i);
        scanf("%lf", &a[i]);
    }
    printf("Сума елементів більших за e: %f\n", sumGreaterE(a, N));
    return 0;
}
