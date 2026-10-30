#include <stdio.h>
#include <locale.h>

int createFile(char fileName[]) {
    FILE *out;
    int x;
    out = fopen(fileName, "wb");
    if (out == NULL) {
        return 0;
    }
    printf("Введіть цілі числа (0 - кінець введення)\n");
    while (1) {
        if (scanf("%d", &x) != 1 || x == 0) {
            break;
        }
        fwrite(&x, sizeof(int), 1, out);
    }
    fclose(out);
    return 1;
}

int printFile(char fileName[]) {
    FILE *in;
    int x;
    in = fopen(fileName, "rb");
    if (in == NULL) {
        return 0;
    }
    while (fread(&x, sizeof(int), 1, in) == 1) {
        printf("%d ", x);
    }
    printf("\n");
    fclose(in);
    return 1;
}

int readNext(FILE *f, int positive, int *x) {
    int v;
    while (fread(&v, sizeof(int), 1, f) == 1) {
        if ((positive && v > 0) || (!positive && v < 0)) {
            *x = v;
            return 1;
        }
    }
    return 0;
}

int main() {
    char fNameF[80], fNameG[80];
    FILE *f, *g, *h, *fp;
    int x, ans, pos = 0, neg = 0, zero = 0, pairs, i, j;
    int lastPos = 0, lastNeg = 0, left;
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

    f = fopen(fNameF, "rb");
    if (f == NULL) {
        printf("Помилка відкриття файлу F\n");
        return 1;
    }
    while (fread(&x, sizeof(int), 1, f) == 1) {
        if (x > 0) pos++;
        else if (x < 0) neg++;
        else zero++;
    }
    if (zero > 0) {
        printf("У файлі є нулі\n");
        fclose(f);
        return 1;
    }
    if (pos != neg) {
        printf("Кількість додатних і від'ємних чисел різна\n");
        fclose(f);
        return 1;
    }

    h = fopen("h.tmp", "wb");
    if (h == NULL) {
        printf("Помилка створення допоміжного файлу\n");
        fclose(f);
        return 1;
    }
    rewind(f);
    while (readNext(f, 0, &x)) {
        fwrite(&x, sizeof(int), 1, h);
    }
    fclose(h);
    h = fopen("h.tmp", "rb");
    g = fopen(fNameG, "wb");
    fp = fopen(fNameF, "rb");
    if (h == NULL || g == NULL || fp == NULL) {
        printf("Помилка відкриття файлів\n");
        if (h) fclose(h);
        if (g) fclose(g);
        if (fp) fclose(fp);
        fclose(f);
        return 1;
    }
    fclose(f);

    pairs = pos / 2;
    for (i = 0; i < pairs; i++) {
        for (j = 0; j < 2; j++) {
            readNext(fp, 1, &x);
            fwrite(&x, sizeof(int), 1, g);
        }
        for (j = 0; j < 2; j++) {
            readNext(h, 0, &x);
            fwrite(&x, sizeof(int), 1, g);
        }
    }
    left = pos - 2 * pairs;
    if (left == 1) {
        readNext(fp, 1, &lastPos);
        readNext(h, 0, &lastNeg);
    }
    fclose(fp);
    fclose(h);
    fclose(g);
    remove("h.tmp");

    printf("Файл G: ");
    printFile(fNameG);
    if (left == 1) {
        printf("Неможливо розташувати останні два числа: %d %d\n", lastPos, lastNeg);
    }
    return 0;
}
