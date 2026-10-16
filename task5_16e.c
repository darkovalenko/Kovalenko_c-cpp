#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    double x, eps, a, s = 0;
    int k = 1;
    setlocale(LC_ALL, "ukr");
    printf("x=");
    scanf("%lf", &x);
    printf("eps=");
    scanf("%lf", &eps);
    a = x;
    while (fabs(a) >= eps) {
        s = s + a;
        k++;
        a = -a * x * (k - 1) / k;
    }
    printf("y = %.10f\n", s);
    printf("ln(1+x) = %.10f\n", log(1 + x));
    return 0;
}
