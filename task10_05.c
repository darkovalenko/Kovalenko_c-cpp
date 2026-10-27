#include <stdio.h>
#include <string.h>
#include <locale.h>

#define NMAX 100
#define NAME 50

typedef struct {
    char name[NAME];
    double height;
} Mountain;

int inputMountains(Mountain a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Назва гори %d: ", i);
        if (scanf(" %49[^\n]", a[i].name) != 1) return 0;
        printf("Висота (м): ");
        if (scanf("%lf", &a[i].height) != 1) return 0;
    }
    return 1;
}

void printMountains(Mountain a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d: %s, %g м\n", i, a[i].name, a[i].height);
    }
}

void printHighest(Mountain a[], int n) {
    int i, best = 0;
    for (i = 1; i < n; i++) {
        if (a[i].height > a[best].height) {
            best = i;
        }
    }
    printf("Найвища вершина: %s\n", a[best].name);
}

void printHeightByName(Mountain a[], int n, char name[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(a[i].name, name) == 0) {
            printf("Висота вершини %s: %g м\n", name, a[i].height);
            return;
        }
    }
    printf("Вершини з назвою %s немає в масиві\n", name);
}

int main() {
    Mountain a[NMAX];
    char name[NAME];
    int n;
    setlocale(LC_ALL, "ukr");
    printf("N=");
    if (scanf("%d", &n) != 1 || n <= 0 || n > NMAX) {
        printf("Некоректне N\n");
        return 1;
    }
    if (!inputMountains(a, n)) {
        printf("Некоректне введення\n");
        return 1;
    }
    printMountains(a, n);
    printHighest(a, n);
    printf("Назва для пошуку: ");
    if (scanf(" %49[^\n]", name) != 1) {
        printf("Некоректне введення\n");
        return 1;
    }
    printHeightByName(a, n, name);
    return 0;
}
