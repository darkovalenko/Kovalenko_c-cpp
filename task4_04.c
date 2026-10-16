#include <stdio.h>
#include <locale.h>

int main() {
    int n, k;
    double x, y = 0, p = 1;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%d", &n);
    printf("x=");
    scanf("%lf", &x);

    for (k = 1; k <= n; k++) {
        p = p * x;
        y = y + k * p;
    }
    printf("y = %f\n", y);
    return 0;
}
