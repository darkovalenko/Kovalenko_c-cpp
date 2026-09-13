#include <stdio.h>
#include <math.h>

int main () {

    double x;
    printf ( "Input real x:");
    scanf ( "%lf", &x );

    int x_int = (int)x;
    printf ( "Integer part: %d", x_int);

    double factorial_part = x_int;
    printf ( "\nFractional part: %lf", fabs(factorial_part));

    int x_floor= floor(x);
    printf ( "\nFloor value: %d", x_floor);

    int x_ceil= ceil(x);
    printf ( "\nCeiling value: %d", x_ceil);   

    int x_round= round(x);
    printf ( "\nRounded value: %d", x_round);
}