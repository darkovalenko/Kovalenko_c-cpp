#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    int n, i;
    double y, z, max;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%d", &n);

    max = 0;
    for (i = 1; i <= n; i++) {
        printf("y[%d]=", i);
        scanf("%lf", &y);
        if (fabs(y) <= 2) {
            z = y;
        } else {
            z = 0.5;
        }
        if (fabs(z) > max) {
            max = fabs(z);
        }
    }
    printf("max = %f\n", max);
    return 0;
}
