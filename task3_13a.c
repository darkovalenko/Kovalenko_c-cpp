#include <stdio.h>

int main() {
    double a1, b1, c1, a2, b2, c2;
    scanf("%lf %lf %lf %lf %lf %lf", &a1, &b1, &c1, &a2, &b2, &c2);

    double D = a1*b2 - a2*b1;

    if (D != 0) {
        double x = (-c1*b2 + c2*b1) / D;
        double y = (-a1*c2 + a2*c1) / D;
        printf("x=%f y=%f\n", x, y);
    } else {
        double Dx = -c1*b2 + c2*b1;
        double Dy = -a1*c2 + a2*c1;

        if (Dx == 0 && Dy == 0) {
            printf("infinite solutions\n");
        } else {
            printf("no solutions\n");
        }
    }

    return 0;
}