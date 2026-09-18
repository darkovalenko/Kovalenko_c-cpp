#include <stdio.h>
#include <math.h>

double square  (double x) {
    return x * x;
}

double Rosenbrock2d(double x, double y) {
    return 100*square(y - square(x)) +square(1 - x);
}

int main(){
    double res[4]={0., 1., 4., 401.};

    printf("Rosenbrock function values:\n");
    printf("Rosenbrock2d(0, 0) = %f\n", Rosenbrock2d(0, 0));
    printf("Rosenbrock2d(1, 1) = %f\n", Rosenbrock2d(1, 1));
    printf("Rosenbrock2d(2, 3) = %f\n", Rosenbrock2d(2, 3));
    printf("Rosenbrock2d(-1, 1) = %f\n", Rosenbrock2d(-1, 1));

    double x,y;
    printf("Input real x, y: \n");
    scanf("%lf %lf", &x, &y);
    printf("Rosenbrock2d(%g, %g) = %g\n", x, y, Rosenbrock2d(x, y));
    return 0;
}