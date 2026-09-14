#include <stdio.h>

int main() {
    double c;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &c);

    double f = 9*c/5 + 32;
    printf("F=%g\n", f);

    return 0;
}