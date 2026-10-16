#include <stdio.h>
#include <locale.h>

int main() {
    long long m, p = 1;
    int k = 0;
    setlocale(LC_ALL, "ukr");
    printf("m=");
    scanf("%lld", &m);

    while (p * 4 <= m) {
        p = p * 4;
        k++;
    }
    printf("k = %d (4^%d = %lld)\n", k, k, p);
    return 0;
}
