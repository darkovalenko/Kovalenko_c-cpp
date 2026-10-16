#include <stdio.h>
#include <locale.h>

int main() {
    long long a = -99, b = -99, c = -99, next;
    int n = 3;
    setlocale(LC_ALL, "ukr");
    while (c <= 0) {
        next = c + a + 100;
        a = b;
        b = c;
        c = next;
        n++;
    }
    printf("Найменший додатний член: x[%d] = %lld\n", n, c);
    return 0;
}
