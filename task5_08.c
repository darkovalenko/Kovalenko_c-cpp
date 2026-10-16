#include <stdio.h>
#include <math.h>
#include <locale.h>

double expTaylor(double x, double eps) {
    double term = 1, s = 0;
    int k = 0;
    while (fabs(term) >= eps) {
        s = s + term;
        k++;
        term = term * x / k;
    }
    return s;
}

double phiTaylor(double x, double eps) {
    double u = x, term = x, s = 0;
    int k = 0;
    while (fabs(term) >= eps) {
        s = s + term;
        k++;
        u = u * (-x * x) / k;
        term = u / (2 * k + 1);
    }
    return s;
}

int main() {
    double x, eps, pi = 3.14159265358979323846;
    setlocale(LC_ALL, "ukr");
    printf("eps=");
    scanf("%lf", &eps);
    printf("x=");
    scanf("%lf", &x);
    printf("а) ряд Тейлора: %.10f, exp(x): %.10f\n", expTaylor(x, eps), exp(x));
    printf("б) ряд Тейлора: %.10f, sqrt(pi)/2*erf(x): %.10f\n", phiTaylor(x, eps), sqrt(pi) / 2 * erf(x));
    return 0;
}
