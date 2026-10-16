#include <stdio.h>
#include <locale.h>

double polyA(double x, int n) {
    double y = 1;
    double p = 1;
    int i;
    for (i = 1; i <= n; i++) {
        p = p * x;
        y = y + p;
    }
    return y;
}

double polyB(double x, double y, int n) {
    double s = 1;
    double px = x;
    double py = 1;
    int k;
    for (k = 1; k <= n; k++) {
        px = px * px;
        py = py * y;
        s = s + px * py;
    }
    return s;
}

int main() {
    setlocale(LC_ALL, "ukr");
    printf("а) y = %f\n", polyA(2, 3));
    printf("б) y = %f\n", polyB(1, 2, 4));
    return 0;
}
