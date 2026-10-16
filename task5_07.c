#include <stdio.h>
#include <locale.h>

int main() {
    int n, k;
    double s, a1, a2, b1, b2, a, b, p;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%d", &n);

    a1 = 0; a2 = 1;
    b1 = 1; b2 = 0;
    s = 2 / (a1 + b1);
    p = 2;
    if (n >= 2) {
        p = 4;
        s = s + p / (a2 + b2);
    }
    for (k = 3; k <= n; k++) {
        p = p * 2;
        b = b2 + a2;
        a = a2 / k + a1 * b;
        s = s + p / (a + b);
        a1 = a2; a2 = a;
        b1 = b2; b2 = b;
    }
    printf("S = %f\n", s);
    return 0;
}
