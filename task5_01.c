#include <stdio.h>
#include <locale.h>

int main() {
    double a, s = 1;
    int n = 1;
    setlocale(LC_ALL, "ukr");
    printf("a=");
    scanf("%lf", &a);
    while (s <= a) {
        n++;
        s = s + 1.0 / n;
    }
    printf("а) перше число більше за a: %f\n", s);
    printf("б) найменше n: %d\n", n);
    return 0;
}
