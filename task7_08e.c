#include <stdio.h>
#include <locale.h>

#define NMAX 100

int isPrime(int x) {
    int d;
    if (x < 2) {
        return 0;
    }
    for (d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            return 0;
        }
    }
    return 1;
}

int countPrimes(int a[], int n) {
    int i, count = 0;
    for (i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    int a[NMAX];
    int n, i;
    setlocale(LC_ALL, "ukr");
    printf("N=");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
    }
    printf("Кількість простих чисел: %d\n", countPrimes(a, n));
    return 0;
}
