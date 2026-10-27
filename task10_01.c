#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char letter;
    int number;
} ChessSquare;

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point a;
    Point b;
} Rectangle;

typedef struct {
    int degree;
    double *coef;
} Polynomial;

int inputDate(Date *d) {
    printf("Число: ");
    if (scanf("%d", &d->day) != 1) return 0;
    printf("Місяць: ");
    if (scanf("%d", &d->month) != 1) return 0;
    printf("Рік: ");
    if (scanf("%d", &d->year) != 1) return 0;
    return 1;
}

void printDate(Date d) {
    printf("%02d.%02d.%d\n", d.day, d.month, d.year);
}

int inputChessSquare(ChessSquare *s) {
    char letter;
    int number;
    printf("Поле (наприклад, a5): ");
    if (scanf(" %c%d", &letter, &number) != 2) return 0;
    if (letter < 'a' || letter > 'h' || number < 1 || number > 8) return 0;
    s->letter = letter;
    s->number = number;
    return 1;
}

void printChessSquare(ChessSquare s) {
    printf("%c%d\n", s.letter, s.number);
}

int inputPoint(Point *p) {
    printf("x=");
    if (scanf("%lf", &p->x) != 1) return 0;
    printf("y=");
    if (scanf("%lf", &p->y) != 1) return 0;
    return 1;
}

void printPoint(Point p) {
    printf("(%g; %g)", p.x, p.y);
}

int inputRectangle(Rectangle *r) {
    printf("Перша вершина\n");
    if (!inputPoint(&r->a)) return 0;
    printf("Протилежна вершина\n");
    if (!inputPoint(&r->b)) return 0;
    return 1;
}

void printRectangle(Rectangle r) {
    printf("Прямокутник: ");
    printPoint(r.a);
    printf(" - ");
    printPoint(r.b);
    printf("\n");
}

int inputPolynomial(Polynomial *p) {
    int i;
    printf("Степінь: ");
    if (scanf("%d", &p->degree) != 1 || p->degree < 0) return 0;
    p->coef = (double *)malloc((p->degree + 1) * sizeof(double));
    if (p->coef == NULL) return 0;
    for (i = 0; i <= p->degree; i++) {
        printf("Коефіцієнт при x^%d: ", i);
        if (scanf("%lf", &p->coef[i]) != 1) {
            free(p->coef);
            p->coef = NULL;
            return 0;
        }
    }
    return 1;
}

void printPolynomial(Polynomial p) {
    int i;
    for (i = p.degree; i >= 0; i--) {
        printf("%+g*x^%d ", p.coef[i], i);
    }
    printf("\n");
}

void freePolynomial(Polynomial *p) {
    free(p->coef);
    p->coef = NULL;
}

int main() {
    Date d;
    ChessSquare s;
    Rectangle r;
    Polynomial p;
    setlocale(LC_ALL, "ukr");

    printf("а) Дата\n");
    if (!inputDate(&d)) {
        printf("Некоректне введення\n");
        return 1;
    }
    printDate(d);

    printf("б) Поле шахової дошки\n");
    if (!inputChessSquare(&s)) {
        printf("Некоректне поле\n");
        return 1;
    }
    printChessSquare(s);

    printf("в) Прямокутник\n");
    if (!inputRectangle(&r)) {
        printf("Некоректне введення\n");
        return 1;
    }
    printRectangle(r);

    printf("г) Поліном\n");
    if (!inputPolynomial(&p)) {
        printf("Некоректне введення\n");
        return 1;
    }
    printPolynomial(p);
    freePolynomial(&p);
    return 0;
}
