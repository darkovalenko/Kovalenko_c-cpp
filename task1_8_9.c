#include <stdio.h>
#include <math.h>

double average(double a, double b) {
    return (a + b) / 2;
}
double harmonic_mean(double a, double b) {
    return 2 / (1/a + 1/b);
}
int main () {
    double x, y;
    printf ( "Input real x, y: \n");
    scanf ( "%lf %lf", &x, &y );

    printf ( "Difference: %lf\n", x - y );
    printf ( "Multiplication: %lf\n", x * y );
    printf ( "Average: %lf\n", average(x, y) );
    printf ( "Harmonic mean: %lf\n", harmonic_mean(x, y) );
    return 0;
}