#include <stdio.h>
#include <math.h>

double cylinderVolume(double r, double h) {
    return M_PI * r * r * h;
}

int main() {
    double r, h;
    printf("Enter radius and height: ");
    scanf("%lf %lf", &r, &h);

    printf("V=%f\n", cylinderVolume(r, h));

    return 0;
}