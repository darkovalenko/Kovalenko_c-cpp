#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    double x, sum = 0, logSum = 0, g;
    long long a, s = 0;
    int i = 0, n = 0, minus = 0;
    setlocale(LC_ALL, "ukr");

    printf("Введіть дійсні числа (0 - кінець введення)\n");
    while (1) {
        printf("a[%d]=", i);
        scanf("%lf", &x);
        if (x == 0) break;
        sum = sum + x;
        i++;
    }
    printf("Сума = %f\n", sum);

    printf("Введіть цілі ненульові числа (0 - кінець введення)\n");
    while (1) {
        printf("a[%d]=", n);
        scanf("%lld", &a);
        if (a == 0) break;
        s = s + a;
        if (a < 0) {
            minus++;
            logSum = logSum + log(-(double)a);
        } else {
            logSum = logSum + log((double)a);
        }
        n++;
    }

    if (n == 0) {
        printf("Послідовність порожня\n");
        return 0;
    }
    printf("Середнє арифметичне = %f\n", (double)s / n);

    g = exp(logSum / n);
    if (minus % 2 == 0) {
        printf("Середнє геометричне = %f\n", g);
    } else if (n % 2 == 1) {
        printf("Середнє геометричне = %f\n", -g);
    } else {
        printf("Середнє геометричне не визначене (від'ємний добуток, парна кількість чисел)\n");
    }
    return 0;
}
