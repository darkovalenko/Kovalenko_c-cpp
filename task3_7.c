#include <stdio.h>
#include <math.h>

void solveQuadratic(double a, double b, double c) {
    if (a == 0) {
        if (b != 0) {
            printf("x=%f\n", -c/b);
        } else if (c == 0) {
            printf("infinite solutions\n");
        } else {
            printf("no solutions\n");
        }
        return;
    }

    double D = b*b - 4*a*c;

    if (D > 0) {
        printf("x1=%f\n", (-b + sqrt(D)) / (2*a));
        printf("x2=%f\n", (-b - sqrt(D)) / (2*a));
    } else if (D == 0) {
        printf("x=%f\n", -b / (2*a));
    } else {
        printf("no real solutions\n");
    }
}

void solveBiquadratic(double a, double b, double c) {
    double D = b*b - 4*a*c;

    if (D < 0) {
        printf("no real solutions\n");
        return;
    }

    double t1 = (-b + sqrt(D)) / (2*a);
    double t2 = (-b - sqrt(D)) / (2*a);

    if (t1 >= 0) {
        printf("x=%f\n", sqrt(t1));
        printf("x=%f\n", -sqrt(t1));
    }

    if (t2 >= 0 && t2 != t1) {
        printf("x=%f\n", sqrt(t2));
        printf("x=%f\n", -sqrt(t2));
    }
}

int main() {
    double a, b, c;

    printf("a) ax^2+bx+c=0\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    solveQuadratic(a, b, c);

    printf("b) ax^4+bx^2+c=0\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    solveBiquadratic(a, b, c);

    return 0;
}