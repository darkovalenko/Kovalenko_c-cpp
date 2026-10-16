#include <stdio.h>
#include <locale.h>

double v(int n) {
    double a = 1, b = 1, c = 1, next;
    int i;
    if (n <= 2) return 1;
    for (i = 3; i <= n; i++) {
        next = (i + 4) * (c - 1) + (i + 5) * a;
        a = b;
        b = c;
        c = next;
    }
    return c;
}

int main() {
    int n;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%d", &n);
    printf("v[%d] = %f\n", n, v(n));
    return 0;
}
