#include <stdio.h>
#include <locale.h>

int main() {
    long long n, p = 1;
    int r = 0;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%lld", &n);

    while (p <= n) {
        p = p * 2;
        r++;
    }
    printf("2^%d = %lld\n", r, p);
    return 0;
}
