#include <stdio.h>
#include <locale.h>

int main() {
    int n, k, j;
    double b, ra, rb, rc;
    setlocale(LC_ALL, "ukr");
    printf("b=");
    scanf("%lf", &b);
    printf("n=");
    scanf("%d", &n);

    ra = b;
    for (k = 1; k <= n; k++) {
        ra = b + 1 / ra;
    }
    printf("а) b[%d] = %f\n", n, ra);

    rb = 4 * n + 2;
    for (k = 1; k <= n; k++) {
        rb = 4 * (n - k) + 2 + 1 / rb;
    }
    printf("б) lambda[%d] = %f\n", n, rb);

    rc = 2;
    for (j = 2 * n - 1; j >= 1; j--) {
        rc = (j % 2 == 1 ? 1 : 2) + 1 / rc;
    }
    printf("в) x[%d] = %f\n", 2 * n, rc);
    return 0;
}
