#include <stdio.h>
#include <math.h>

double triangleArea(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    double a, b, c;
    printf("Enter a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("S=%f\n", triangleArea(a, b, c));

    return 0;
}