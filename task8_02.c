#include <stdio.h>
#include <locale.h>

#define SIZE 3

int main() {
    double a[SIZE][SIZE] = {
        {1.0, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int i, j, k;
    double x;
    setlocale(LC_ALL, "ukr");
    printf("i=");
    scanf("%d", &i);
    printf("j=");
    scanf("%d", &j);
    printf("a=");
    scanf("%lf", &x);
    if (i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
        a[i][j] = x;
    } else {
        printf("Некоректні індекси\n");
    }
    for (k = 0; k < SIZE; k++) {
        for (j = 0; j < SIZE; j++) {
            printf("\t%g", a[k][j]);
        }
        printf("\n");
    }
    return 0;
}
