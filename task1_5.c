#include <stdio.h>

int main() {

    int x=2;
    printf("x = %d", x);

    int y=x*x;
    y=y*x;
    printf("\ny = %d", y);

    return 0;
}