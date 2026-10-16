#include <stdio.h>
#include <locale.h>

unsigned long long doubleFact(int n) {
    unsigned long long y = 1;
    int i;
    for (i = n; i > 1; i = i - 2) {
        y = y * i;
    }
    return y;
}

int main() {
    int n;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%d", &n);
    printf("%d!! = %llu\n", n, doubleFact(n));
    return 0;
}
