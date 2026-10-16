#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    int n, i, k;
    double a, b;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%d", &n);

    a = sqrt(2.0);
    for (i = 2; i <= n; i++) {
        a = sqrt(2 + a);
    }
    printf("а) %f\n", a);

    b = sqrt(3.0 * n);
    for (k = n - 1; k >= 1; k--) {
        b = sqrt(3.0 * k + b);
    }
    printf("б) %f\n", b);
    return 0;
}
