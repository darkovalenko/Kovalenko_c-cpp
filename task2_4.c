#include<stdio.h>

double calculate_polinomial(double x) {
    double x3 = x*x*x;
    double x9 = x3*x3*x3;

    return x9 + x3 + 1.0;
}

int main () {

    double x;
    printf("Enter a value for x: ");
    scanf("%lf", &x);
    
    double result = calculate_polinomial(x);
    printf("The result of the polynomial is: %lf\n", result);
    return 0;
}