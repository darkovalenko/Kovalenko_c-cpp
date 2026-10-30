#include <stdio.h>
#include <math.h>
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

int isEven(int x) {
    return x % 2 == 0;
}

int isPowerOfThree(int x) {
    if (x < 1) {
        return 0;
    }
    while (x % 3 == 0) {
        x = x / 3;
    }
    return x == 1;
}

int isSquare(int x) {
    long long r;
    if (x < 0) {
        return 0;
    }
    r = (long long)(sqrt((double)x) + 0.5);
    return r * r == x;
}

int isPrime(long long x) {
    long long d;
    if (x < 2) {
        return 0;
    }
    for (d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            return 0;
        }
    }
    return 1;
}

int hasThreeDivisors(int x) {
    long long r;
    if (x < 4) {
        return 0;
    }
    r = (long long)(sqrt((double)x) + 0.5);
    return r * r == x && isPrime(r);
}

int isPalindrome(int x) {
    long long rev = 0, t = x;
    if (x < 0) {
        return 0;
    }
    while (t > 0) {
        rev = rev * 10 + t % 10;
        t = t / 10;
    }
    return rev == x;
}

int isFibonacci(int x) {
    long long a = 0, b = 1, t;
    if (x < 0) {
        return 0;
    }
    while (a < x) {
        t = a + b;
        a = b;
        b = t;
    }
    return a == x;
}

int filterFile(char fNameF[], char fNameG[], int (*pred)(int)) {
    FILE *f, *g;
    int x;
    f = fopen(fNameF, "rb");
    if (f == NULL) {
        return 0;
    }
    g = fopen(fNameG, "wb");
    if (g == NULL) {
        fclose(f);
        return 0;
    }
    while (fread(&x, sizeof(int), 1, f) == 1) {
        if (pred(x)) {
            fwrite(&x, sizeof(int), 1, g);
        }
    }
    fclose(f);
    fclose(g);
    return 1;
}

int main() {
    char fNameF[80];
    char *gNames[6] = {"g_a.bin", "g_b.bin", "g_v.bin", "g_g.bin", "g_d.bin", "g_e.bin"};
    char *titles[6] = {"а) парні", "б) степені 3", "в) точні квадрати", "г) мають лише 3 дільники", "д) паліндроми", "е) числа Фібоначчі"};
    int (*preds[6])(int) = {isEven, isPowerOfThree, isSquare, hasThreeDivisors, isPalindrome, isFibonacci};
    int i;
    setlocale(LC_ALL, "ukr");
    printf("Ім'я файлу F: ");
    scanf("%79s", fNameF);
    if (!createFile(fNameF)) {
        printf("Помилка створення файлу\n");
        return 1;
    }
    printf("Файл F: ");
    printFile(fNameF);
    for (i = 0; i < 6; i++) {
        if (!filterFile(fNameF, gNames[i], preds[i])) {
            printf("Помилка роботи з файлами\n");
            return 1;
        }
        printf("%s (%s): ", titles[i], gNames[i]);
        printFile(gNames[i]);
    }
    return 0;
}
