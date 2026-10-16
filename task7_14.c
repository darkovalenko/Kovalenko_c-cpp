#include <stdio.h>
#include <math.h>
#include <locale.h>

#define N 10

double average(double a[], int n) {
    double s = 0;
    int i;
    for (i = 0; i < n; i++) {
        s = s + a[i];
    }
    return s / n;
}

double variation(double a[], int n) {
    double m = average(a, n), s = 0;
    int i;
    for (i = 0; i < n; i++) {
        s = s + (a[i] - m) * (a[i] - m);
    }
    return s / n;
}

int main() {
    double a[N];
    int i;
    setlocale(LC_ALL, "ukr");
    for (i = 0; i < N; i++) {
        printf("A[%d]=", i);
        scanf("%lf", &a[i]);
    }
    printf("Варіація (середній квадрат відхилення): %f\n", variation(a, N));
    printf("Середнє квадратичне відхилення: %f\n", sqrt(variation(a, N)));
    return 0;
}
