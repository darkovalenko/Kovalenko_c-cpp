#include <stdio.h>

int main() {
    double m1, m2, r;
    printf("Enter m1, m2, r: ");
    scanf("%lf %lf %lf", &m1, &m2, &r);

    double gamma = 6.673e-11;
    double F = gamma * m1 * m2 / (r * r);

    printf("F=%e\n", F);

    return 0;
}