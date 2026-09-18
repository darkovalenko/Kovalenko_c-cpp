#include <stdio.h>
#include <math.h>


double square(double x) {
    return x * x;
}

double hypotenuse_squared(double a, double b) {
    return square(a) + square(b);
}

double hypotenuse(double a, double b) {
    return sqrt(hypotenuse_squared(a, b));
}

int main() {
    double a, b, c;
    printf("Enter 2 slides:  ");
    scanf("%lf %lf", &a, &b);
    c=hypotenuse(a, b);
    printf("Hypotenuse: %g %g\n", hypot(a, b));

    return 0;
}