#include <stdio.h>
#include <math.h>

double gauss(double x) {
    return exp(-x*x);
}

double gauss_derivative(double x) {
    return -2*x*exp(-x*x);
}

int main() {
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);

    printf("f(x)=%f\n", gauss(x));
    printf("g(x)=%f\n", gauss_derivative(x));

    return 0;
}