#include <stdio.h>

int main() {
    double a, t, v;
    printf("Enter a, t, v: ");
    scanf("%lf %lf %lf", &a, &t, &v);

    double s = a * t * t / 2;
    printf("s=%f\n", s);

    double t1 = v / a;
    printf("t=%f\n", t1);

    return 0;
}