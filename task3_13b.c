#include <stdio.h>
#include <math.h>

#define EPS 1e-9

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    double D = b - a;

    if (fabs(D) > EPS) {
        double x1 = (b + c) / D;
        double y1 = (-c - a) / D;
        printf("x=%f y=%f\n", x1, y1);

        double x2 = (-b + c) / D;
        double y2 = (-c + a) / D;
        printf("x=%f y=%f\n", x2, y2);
    } else if (fabs(a) < EPS) {
        if (fabs(c) < EPS) {
            printf("infinite solutions\n");
        } else {
            printf("no solutions\n");
        }
    } else {
        double s = -c / a;

        if (fabs(s - 1) < EPS || fabs(s + 1) < EPS) {
            printf("infinite solutions\n");
        } else {
            printf("no solutions\n");
        }
    }

    return 0;
}