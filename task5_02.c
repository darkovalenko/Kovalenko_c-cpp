#include <stdio.h>
#include <locale.h>

long long fib(int n) {
    long long prev = 0, cur = 1, next;
    int i;
    if (n == 0) return 0;
    for (i = 2; i <= n; i++) {
        next = prev + cur;
        prev = cur;
        cur = next;
    }
    return cur;
}

int maxFibIndex(double a) {
    long long prev = 0, cur = 1, next;
    int i = 0;
    while (cur <= a) {
        next = prev + cur;
        prev = cur;
        cur = next;
        i++;
    }
    return i;
}

int minFibIndex(double a) {
    long long prev = 0, cur = 1, next;
    int i = 0;
    while (prev <= a) {
        next = prev + cur;
        prev = cur;
        cur = next;
        i++;
    }
    return i;
}

long long fibSum(int limit) {
    long long prev = 0, cur = 1, next, s = 0;
    while (prev <= limit) {
        s = s + prev;
        next = prev + cur;
        prev = cur;
        cur = next;
    }
    return s;
}

int main() {
    int n;
    double a;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%d", &n);
    printf("a=");
    scanf("%lf", &a);
    printf("а) F[%d] = %lld\n", n, fib(n));
    printf("б) номер найбільшого числа Фібоначчі, що не перевищує a: %d\n", maxFibIndex(a));
    printf("в) номер найменшого числа Фібоначчі, що більше за a: %d\n", minFibIndex(a));
    printf("г) сума чисел Фібоначчі, що не перевищують 1000: %lld\n", fibSum(1000));
    return 0;
}
