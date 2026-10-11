#include <stdio.h>

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);

    double max = a > b ? a : b;
    double min = a < b ? a : b;

    printf("max=%f\n", max);
    printf("min=%f\n", min);

    return 0;
}