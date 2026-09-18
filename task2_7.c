#include <stdio.h>
#include <math.h>

double square(double x) {
    return x * x;
}

double lenght(double x1, double y1, double x2, double y2) {
    return hypot(x2 - x1, y2 - y1);
}

double area_heron(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = lenght(x1, y1, x2, y2);
    double b = lenght(x2, y2, x3, y3);
    double c = lenght(x1, y1, x3, y3);
    return area_heron(a, b, c);
}

int main() {

    printf("Lenght beetween points (1, 2) and (4, 6): %lf\n", lenght(1, 2, 4, 6));
    printf("Lenght beetween points (4, 6) and (7, 10): %lf\n", lenght(4, 6, 7, 10));
    printf("Lenght beetween points (7, 10) and (1, 2): %lf\n", lenght(7, 10, 1, 2));

    printf("Area of triangle with vertices (1, 2), (4, 6), (7, 10): %lf\n", triangle_area(1, 2, 4, 6, 7, 10));
    printf("Area of triangle with vertices (0, 0), (4, 0), (2, 3): %lf\n", triangle_area(0, 0, 4, 0, 2, 3));

    double x1, y1, x2, y2, x3, y3;
    printf("Enter coordinates of 3 points (x1 y1 x2 y2 x3 y3): ");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    
    double area = triangle_area(x1, y1, x2, y2, x3, y3);
    printf("Area of the triangle: %lf\n", area);
    return 0;
}