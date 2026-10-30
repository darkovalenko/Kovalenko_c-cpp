#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int createFile(char fileName[]) {
    FILE *out;
    double x;
    out = fopen(fileName, "wb");
    if (out == NULL) {
        return 0;
    }
    printf("Введіть дійсні числа (0 - кінець введення)\n");
    while (1) {
        if (scanf("%lf", &x) != 1 || x == 0) {
            break;
        }
        fwrite(&x, sizeof(double), 1, out);
    }
    fclose(out);
    return 1;
}

int printFile(char fileName[]) {
    FILE *in;
    double x;
    in = fopen(fileName, "rb");
    if (in == NULL) {
        return 0;
    }
    while (fread(&x, sizeof(double), 1, in) == 1) {
        printf("%g ", x);
    }
    printf("\n");
    fclose(in);
    return 1;
}

int splitFile(char fNameF[], char fNameG[], double a) {
    FILE *f, *g, *t;
    double x;
    char tmpName[100];
    sprintf(tmpName, "%s.tmp", fNameF);
    f = fopen(fNameF, "rb");
    if (f == NULL) {
        return 0;
    }
    g = fopen(fNameG, "wb");
    if (g == NULL) {
        fclose(f);
        return 0;
    }
    t = fopen(tmpName, "wb");
    if (t == NULL) {
        fclose(f);
        fclose(g);
        return 0;
    }
    while (fread(&x, sizeof(double), 1, f) == 1) {
        if (fabs(x) < a) {
            fwrite(&x, sizeof(double), 1, g);
        } else {
            fwrite(&x, sizeof(double), 1, t);
        }
    }
    fclose(f);
    fclose(g);
    fclose(t);
    if (remove(fNameF) != 0) {
        return 0;
    }
    if (rename(tmpName, fNameF) != 0) {
        return 0;
    }
    return 1;
}

int main() {
    char fNameF[80], fNameG[80];
    double a;
    int ans;
    setlocale(LC_ALL, "ukr");
    printf("Ім'я файлу F: ");
    scanf("%79s", fNameF);
    printf("Створити файл F з консолі (1 так, 0 ні)? ");
    if (scanf("%d", &ans) != 1) {
        printf("Некоректне введення\n");
        return 1;
    }
    if (ans && !createFile(fNameF)) {
        printf("Помилка створення файлу\n");
        return 1;
    }
    printf("Ім'я файлу G: ");
    scanf("%79s", fNameG);
    printf("a=");
    if (scanf("%lf", &a) != 1 || a <= 0) {
        printf("Некоректне a\n");
        return 1;
    }
    if (!splitFile(fNameF, fNameG, a)) {
        printf("Помилка роботи з файлами\n");
        return 1;
    }
    printf("Файл G: ");
    printFile(fNameG);
    printf("Файл F після видалення: ");
    printFile(fNameF);
    return 0;
}
