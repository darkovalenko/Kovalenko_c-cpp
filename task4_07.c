#include <stdio.h>
#include <locale.h>

int main() {
    double x, y = 1, term = 1;
    int n, k;
    setlocale(LC_ALL, "ukr");
    printf("x=");
    scanf("%lf", &x);
    printf("n=");
    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        term = term * x / k;
        y = y + term;
    }
    printf("y = %f\n", y);
    return 0;
}
