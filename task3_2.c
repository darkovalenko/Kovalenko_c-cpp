#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a = n / 100;
    int b = (n / 10) % 10;
    int c = n % 10;

    if (a != b && b != c && a != c) {
        printf("%d\n", a*100 + b*10 + c);
        printf("%d\n", a*100 + c*10 + b);
        printf("%d\n", b*100 + a*10 + c);
        printf("%d\n", b*100 + c*10 + a);
        printf("%d\n", c*100 + a*10 + b);
        printf("%d\n", c*100 + b*10 + a);
    }

    return 0;
}