#include <stdio.h>
#include <locale.h>

#define N 5

void inputArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
    }
}

void printMax(int a[], int n) {
    int i, max = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    printf("Максимальне значення: %d\n", max);
}

int main() {
    int a[N];
    setlocale(LC_ALL, "ukr");
    inputArray(a, N);
    printMax(a, N);
    return 0;
}
