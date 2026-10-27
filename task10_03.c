#include <stdio.h>
#include <locale.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

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

int isValidDate(Date d) {
    if (d.year < 1 || d.month < 1 || d.month > 12) {
        return 0;
    }
    return d.day >= 1 && d.day <= daysInMonth(d.month, d.year);
}

Date tomorrow(Date d) {
    if (d.day < daysInMonth(d.month, d.year)) {
        d.day++;
    } else {
        d.day = 1;
        if (d.month < 12) {
            d.month++;
        } else {
            d.month = 1;
            d.year++;
        }
    }
    return d;
}

int dayOfWeek(Date d) {
    int t[12] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int y = d.year;
    if (d.month < 3) {
        y--;
    }
    return (y + y / 4 - y / 100 + y / 400 + t[d.month - 1] + d.day) % 7;
}

int main() {
    Date d, next;
    char *names[7] = {"неділя", "понеділок", "вівторок", "середа", "четвер", "п'ятниця", "субота"};
    setlocale(LC_ALL, "ukr");
    printf("Число: ");
    if (scanf("%d", &d.day) != 1) {
        printf("Некоректне введення\n");
        return 1;
    }
    printf("Місяць: ");
    if (scanf("%d", &d.month) != 1) {
        printf("Некоректне введення\n");
        return 1;
    }
    printf("Рік: ");
    if (scanf("%d", &d.year) != 1) {
        printf("Некоректне введення\n");
        return 1;
    }
    if (!isValidDate(d)) {
        printf("Такої дати не існує\n");
        return 1;
    }
    next = tomorrow(d);
    printf("Завтра: %02d.%02d.%d\n", next.day, next.month, next.year);
    printf("День тижня: %s\n", names[dayOfWeek(d)]);
    return 0;
}
