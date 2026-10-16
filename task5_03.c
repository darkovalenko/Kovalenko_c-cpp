#include <stdio.h>
#include <locale.h>

int steps(long long a) {
    int k = 0;
    while (a != 1) {
        if (a % 2 == 0) a = a / 2;
        else a = 3 * a + 1;
        k++;
    }
    return k;
}

int main() {
    int n, i, best = 1, bestSteps = 0, s;
    setlocale(LC_ALL, "ukr");
    printf("n=");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        s = steps(i);
        if (s > bestSteps) {
            bestSteps = s;
            best = i;
        }
    }
    printf("Число %d, кількість кроків: %d\n", best, bestSteps);
    return 0;
}
