#include <stdio.h>
#include <locale.h>

int main() {
    int n, i;
    double pa = 1, pb = 1, fact = 1, pow2 = 1, sign = 1;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        fact = fact * i;
        pow2 = pow2 * 2;
        pa = pa * (1 + 1 / fact);
        pb = pb * (1 + sign * i * i / pow2);
        sign = -sign;
    }
    printf("а) P = %f\n", pa);
    printf("б) P = %f\n", pb);
    return 0;
}
