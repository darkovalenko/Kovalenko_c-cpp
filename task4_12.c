#include <stdio.h>
#include <locale.h>

typedef unsigned __int128 big;

void printBig(big v) {
    char buf[64];
    int len = 0;
    if (v == 0) {
        printf("0");
        return;
    }
    while (v > 0) {
        buf[len++] = (char)('0' + (int)(v % 10));
        v = v / 10;
    }
    while (len > 0) {
        putchar(buf[--len]);
    }
}

big subFact(int n) {
    big d = 1;
    int k;
    for (k = 1; k <= n; k++) {
        if (k % 2 == 0) d = d * k + 1;
        else            d = d * k - 1;
    }
    return d;
}

int main() {
    int n;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%d", &n);
    if (n < 0 || n >= 25) {
        printf("Потрібно 0 <= n < 25\n");
        return 0;
    }
    printf("!%d = ", n);
    printBig(subFact(n));
    printf("\n");
    return 0;
}
