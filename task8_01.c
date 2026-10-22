#include <stdio.h>
#include <locale.h>

#define SIZE 3

int main() {
    int a[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int i, j, n, m;
    setlocale(LC_ALL, "ukr");
    printf("N=");
    scanf("%d", &n);
    printf("M=");
    scanf("%d", &m);
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (a[i][j] == m) {
                a[i][j] = n;
            }
        }
    }
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("\t%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
