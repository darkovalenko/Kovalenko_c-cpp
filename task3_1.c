#include <stdio.h>

int main() {

    unsigned n;
    printf("Enter a 3-digit number: ");
    scanf("%u", &n);

    int hundreds = n / 100;
    int tens = (n / 10) % 10;
    int units = n % 10;

    printf("Hundreds: %d\n", hundreds);
    printf("Tens: %d\n", tens);
    printf("Units: %d\n", units);

}