#include <stdio.h>

double rosenbrock2d(double x, double y) {
    return 100 * (x*x - y) * (x*x - y) + (x - 1) * (x - 1);
}

int main() {
    printf("%f\n", rosenbrock2d(1, 1));
    printf("%f\n", rosenbrock2d(0, 0));
    printf("%f\n", rosenbrock2d(2, 3.5));

    return 0;
}