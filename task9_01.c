#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    int n, i;
    double *a, s = 0;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некоректне n\n");
        return 1;
    }
    a = (double *)malloc(n * sizeof(double));
    if (a == NULL) {
        printf("Не вдалося виділити пам'ять\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("a[%d]=", i);
        if (scanf("%lf", &a[i]) != 1) {
            printf("Некоректне введення\n");
            free(a);
            return 1;
        }
    }
    for (i = 0; i < n; i++) {
        s = s + a[i] * a[i];
    }
    printf("Сума квадратів = %g\n", s);
    free(a);
    return 0;
}
