#include <stdio.h>
#include <locale.h>

int main() {
    int n, k;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%d", &n);

    printf("%d! = 1", n);
    for (k = 2; k <= n; k++) {
        printf("*%d", k);
    }
    printf("\n");

    printf("%d! = %d", n, n);
    for (k = n - 1; k >= 1; k--) {
        printf("*%d", k);
    }
    printf("\n");
    return 0;
}
