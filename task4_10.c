#include <stdio.h>
#include <float.h>
#include <locale.h>

int main() {

    volatile float a = 1.0f;
    volatile float s;
    setlocale(LC_ALL, "ukr");

    do {
        a = a / 2;
        s = 1.0f + a;
    } while (s != 1.0f);

    printf("a = %e\n", a);

    printf("FLT_EPSILON = %e\n", FLT_EPSILON);
    printf("FLT_EPSILON/2 = %e\n", FLT_EPSILON / 2);
    if (a == FLT_EPSILON / 2) {
        printf("Значення збігається з FLT_EPSILON/2\n");
    } else {
        printf("Значення не збігається\n");
    }
    return 0;
}
