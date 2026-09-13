#include <stdio.h>

int main() {
    double T = 365 + 1 / (4 + 1 / (7 + 1 / (1 + 1.0/3)));
    printf("%f\n", T);

    return 0;
}