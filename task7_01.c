#include <stdio.h>
#include <locale.h>

#define N 5

int main() {
    int a[N] = {7, -2, 15, 4, 9};
    int i, count = 0;
    double x;
    setlocale(LC_ALL, "ukr");
    printf("x=");
    scanf("%lf", &x);
    for (i = 0; i < N; i++) {
        if (a[i] < x) {
            count++;
        }
    }
    printf("Кількість чисел менших за %f: %d\n", x, count);
    return 0;
}
