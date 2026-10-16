#include <stdio.h>
#include <locale.h>

#define NMAX 50

void countEvenOdd(int a[], int n, int *even, int *odd) {
    int i;
    *even = 0;
    *odd = 0;
    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            (*even)++;
        } else {
            (*odd)++;
        }
    }
}

int main() {
    int a[NMAX];
    int n = 0, x, even, odd;
    setlocale(LC_ALL, "ukr");
    while (n < NMAX) {
        printf("a[%d]=", n);
        scanf("%d", &x);
        if (x == 0) {
            break;
        }
        a[n] = x;
        n++;
    }
    countEvenOdd(a, n, &even, &odd);
    printf("Парних: %d\n", even);
    printf("Непарних: %d\n", odd);
    return 0;
}
