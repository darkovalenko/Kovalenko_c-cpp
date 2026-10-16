#include <stdio.h>
#include <math.h>
#include <locale.h>

double sinN(double x, int n) {
    double y = x;
    int i;
    for (i = 0; i < n; i++) {
        y = sin(y);
    }
    return y;
}

int main() {
    double x;
    int n;
    setlocale(LC_ALL, "ukr");
    printf("x=");
    scanf("%lf", &x);
    printf("n=");
    scanf("%d", &n);
    printf("y = %f\n", sinN(x, n));
    return 0;
}
