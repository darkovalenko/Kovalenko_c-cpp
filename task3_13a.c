#include <stdio.h>
#include <math.h>

#define EPS 1e-9

int main() {
    double a1, b1, c1, a2, b2, c2;
    scanf("%lf %lf %lf %lf %lf %lf", &a1, &b1, &c1, &a2, &b2, &c2);

    double D = a1*b2 - a2*b1;

    if (fabs(D) > EPS) {
        double x = (-c1*b2 + c2*b1) / D;
        double y = (-a1*c2 + a2*c1) / D;
        printf("x=%f y=%f\n", x, y);
    } else {
        double Dx = -c1*b2 + c2*b1;
        double Dy = -a1*c2 + a2*c1;

        if (fabs(Dx) < EPS && fabs(Dy) < EPS) {
            printf("infinite solutions\n");
        } else {
            printf("no solutions\n");
        }
    }

    return 0;
}