#include <stdio.h>
#include <stdint.h>

uint16_t multiply(uint8_t a, uint8_t b) {
    return (uint16_t)a * (uint16_t)b;
}

int main() {
    unsigned int a, b;
    scanf("%u %u", &a, &b);

    uint16_t result = multiply((uint8_t)a, (uint8_t)b);
    printf("%u\n", result);

    return 0;
}