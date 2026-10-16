#include <stdio.h>
#include <locale.h>

#define N 4

int main() {
    int a[N] = {5, 112, 4, 3};
    int i;
    setlocale(LC_ALL, "ukr");
    for (i = N - 1; i >= 0; i--) {
        printf("%d", a[i]);
        if (i > 0) {
            printf(",");
        }
    }
    printf("\n");
    return 0;
}
