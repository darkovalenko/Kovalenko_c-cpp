#include <stdio.h>
#include <locale.h>

typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int minute;
} DateTime;

int isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int daysInMonth(int month, int year) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeap(year)) {
        return 29;
    }
    return days[month - 1];
}

int isValidDateTime(DateTime t) {
    if (t.year < 1 || t.month < 1 || t.month > 12) {
        return 0;
    }
    if (t.day < 1 || t.day > daysInMonth(t.month, t.year)) {
        return 0;
    }
    return t.hour >= 0 && t.hour < 24 && t.minute >= 0 && t.minute < 60;
}

int inputDateTime(DateTime *t) {
    DateTime x;
    printf("Число: ");
    if (scanf("%d", &x.day) != 1) return 0;
    printf("Місяць: ");
    if (scanf("%d", &x.month) != 1) return 0;
    printf("Рік: ");
    if (scanf("%d", &x.year) != 1) return 0;
    printf("Година: ");
    if (scanf("%d", &x.hour) != 1) return 0;
    printf("Хвилина: ");
    if (scanf("%d", &x.minute) != 1) return 0;
    if (!isValidDateTime(x)) return 0;
    *t = x;
    return 1;
}

void printDateTime(DateTime t) {
    printf("%02d.%02d.%d %02d:%02d\n", t.day, t.month, t.year, t.hour, t.minute);
}

int main() {
    DateTime t;
    setlocale(LC_ALL, "ukr");
    if (!inputDateTime(&t)) {
        printf("Некоректна дата або час\n");
        return 1;
    }
    printDateTime(t);
    return 0;
}
