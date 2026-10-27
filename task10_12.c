#include <stdio.h>
#include <math.h>
#include <locale.h>

#define NMAX 100
#define NAME 50

typedef struct {
    char name[NAME];
    int uah;
    int kop;
} Goods;

long long cost(Goods g) {
    return (long long)g.uah * 100 + g.kop;
}

int inputGoods(Goods a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Назва товару %d: ", i);
        if (scanf(" %49[^\n]", a[i].name) != 1) return 0;
        printf("Гривні: ");
        if (scanf("%d", &a[i].uah) != 1 || a[i].uah < 0) return 0;
        printf("Копійки: ");
        if (scanf("%d", &a[i].kop) != 1 || a[i].kop < 0 || a[i].kop > 99) return 0;
    }
    return 1;
}

void printGoods(Goods g) {
    printf("%s: %d грн %02d коп\n", g.name, g.uah, g.kop);
}

int cheapest(Goods a[], int n) {
    int i, best = 0;
    for (i = 1; i < n; i++) {
        if (cost(a[i]) < cost(a[best])) {
            best = i;
        }
    }
    return best;
}

int mostExpensive(Goods a[], int n) {
    int i, best = 0;
    for (i = 1; i < n; i++) {
        if (cost(a[i]) > cost(a[best])) {
            best = i;
        }
    }
    return best;
}

int printNearAverage(Goods a[], int n) {
    int i, count = 0;
    double avg = 0;
    for (i = 0; i < n; i++) {
        avg = avg + cost(a[i]);
    }
    avg = avg / n;
    printf("Середня вартість: %.2f грн\n", avg / 100);
    for (i = 0; i < n; i++) {
        if (fabs(cost(a[i]) - avg) <= 1000) {
            printGoods(a[i]);
            count++;
        }
    }
    return count;
}

int main() {
    Goods a[NMAX];
    int n;
    setlocale(LC_ALL, "ukr");
    printf("N=");
    if (scanf("%d", &n) != 1 || n <= 0 || n > NMAX) {
        printf("Некоректне N\n");
        return 1;
    }
    if (!inputGoods(a, n)) {
        printf("Некоректне введення\n");
        return 1;
    }
    printf("а) Найдешевший товар\n");
    printGoods(a[cheapest(a, n)]);
    printf("б) Найдорожчий товар\n");
    printGoods(a[mostExpensive(a, n)]);
    printf("в) Товари, вартість яких відрізняється від середньої не більше ніж на 10 грн\n");
    if (printNearAverage(a, n) == 0) {
        printf("Таких товарів немає\n");
    }
    return 0;
}
