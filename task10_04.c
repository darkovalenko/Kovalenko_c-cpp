#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int numerator;
    unsigned int denominator;
} Rational;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    unsigned long long t;
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

Rational makeRational(long long num, unsigned long long den) {
    Rational r;
    unsigned long long absNum = num < 0 ? (unsigned long long)(-num) : (unsigned long long)num;
    unsigned long long g = gcd(absNum, den);
    if (g == 0) {
        g = 1;
    }
    r.numerator = (int)(num / (long long)g);
    r.denominator = (unsigned int)(den / g);
    return r;
}

Rational reduce(Rational a) {
    return makeRational(a.numerator, a.denominator);
}

Rational add(Rational a, Rational b) {
    long long num = (long long)a.numerator * b.denominator + (long long)b.numerator * a.denominator;
    unsigned long long den = (unsigned long long)a.denominator * b.denominator;
    return makeRational(num, den);
}

Rational multiply(Rational a, Rational b) {
    long long num = (long long)a.numerator * b.numerator;
    unsigned long long den = (unsigned long long)a.denominator * b.denominator;
    return makeRational(num, den);
}

int compare(Rational a, Rational b) {
    long long left = (long long)a.numerator * b.denominator;
    long long right = (long long)b.numerator * a.denominator;
    if (left < right) return -1;
    if (left > right) return 1;
    return 0;
}

int inputRational(Rational *r) {
    int num;
    unsigned int den;
    printf("Чисельник: ");
    if (scanf("%d", &num) != 1) return 0;
    printf("Знаменник: ");
    if (scanf("%u", &den) != 1 || den == 0) return 0;
    r->numerator = num;
    r->denominator = den;
    return 1;
}

void printRational(Rational r) {
    if (r.denominator == 1) {
        printf("%d", r.numerator);
    } else {
        printf("%d/%u", r.numerator, r.denominator);
    }
}

int main() {
    Rational a, b, c;
    int cmp;
    setlocale(LC_ALL, "ukr");
    printf("Перше число\n");
    if (!inputRational(&a)) {
        printf("Некоректне введення\n");
        return 1;
    }
    printf("Друге число\n");
    if (!inputRational(&b)) {
        printf("Некоректне введення\n");
        return 1;
    }
    printf("Скорочене перше: ");
    printRational(reduce(a));
    printf("\nСкорочене друге: ");
    printRational(reduce(b));
    c = add(a, b);
    printf("\nСума: ");
    printRational(c);
    c = multiply(a, b);
    printf("\nДобуток: ");
    printRational(c);
    cmp = compare(a, b);
    printf("\nПорівняння: ");
    if (cmp < 0) {
        printf("перше менше за друге\n");
    } else if (cmp > 0) {
        printf("перше більше за друге\n");
    } else {
        printf("числа рівні\n");
    }
    return 0;
}
