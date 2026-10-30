#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int writeArray(char fileName[], double a[], int n) {
    FILE *out;
    out = fopen(fileName, "wb");
    if (out == NULL) {
        return 0;
    }
    if (fwrite(a, sizeof(double), n, out) != (size_t)n) {
        fclose(out);
        return 0;
    }
    fclose(out);
    return 1;
}

int printFile(char fileName[]) {
    FILE *in;
    double x;
    int first = 1;
    in = fopen(fileName, "rb");
    if (in == NULL) {
        return 0;
    }
    while (fread(&x, sizeof(double), 1, in) == 1) {
        if (!first) {
            printf(", ");
        }
        printf("%g", x);
        first = 0;
    }
    printf("\n");
    fclose(in);
    return 1;
}

int main() {
    char fileName[80];
    double *a;
    int n, i;
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
    printf("Ім'я файлу: ");
    scanf("%79s", fileName);
    if (!writeArray(fileName, a, n)) {
        printf("Помилка запису у файл\n");
        free(a);
        return 1;
    }
    free(a);
    if (!printFile(fileName)) {
        printf("Помилка читання файлу\n");
        return 1;
    }
    return 0;
}
