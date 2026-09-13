#include <stdio.h>

int main() {
    int a;
    printf("Enter a digit: ");
    scanf("%d", &a);

    printf("a)\n");
    printf("- %d - %d - %d\n", a, a, a);
    printf("%d | %d | %d\n", a, a, a);
    printf("- %d - %d - %d,\n", a, a, a);

    return 0;
}