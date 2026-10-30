#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef struct {
    double x1, y1;
    double x2, y2;
} Rect;

double area(Rect r) {
    return fabs((r.x2 - r.x1) * (r.y1 - r.y2));
}

int inputRect(Rect *r) {
    Rect t;
    printf("Верхній лівий кут: x y = ");
    if (scanf("%lf%lf", &t.x1, &t.y1) != 2) return 0;
    printf("Нижній правий кут: x y = ");
    if (scanf("%lf%lf", &t.x2, &t.y2) != 2) return 0;
    if (t.x1 >= t.x2 || t.y1 <= t.y2) return 0;
    *r = t;
    return 1;
}

int appendRect(char fileName[], Rect r) {
    FILE *f;
    f = fopen(fileName, "ab");
    if (f == NULL) {
        return 0;
    }
    if (fwrite(&r, sizeof(Rect), 1, f) != 1) {
        fclose(f);
        return 0;
    }
    fclose(f);
    return 1;
}

int printRects(char fileName[]) {
    FILE *f;
    Rect r;
    int k = 1;
    f = fopen(fileName, "rb");
    if (f == NULL) {
        return 0;
    }
    while (fread(&r, sizeof(Rect), 1, f) == 1) {
        printf("%d: (%g; %g) (%g; %g) площа %g\n", k, r.x1, r.y1, r.x2, r.y2, area(r));
        k++;
    }
    fclose(f);
    return 1;
}

int maxAreaNumber(char fileName[]) {
    FILE *f;
    Rect r;
    int k = 1, best = 0;
    double maxArea = 0;
    f = fopen(fileName, "rb");
    if (f == NULL) {
        return 0;
    }
    while (fread(&r, sizeof(Rect), 1, f) == 1) {
        if (best == 0 || area(r) > maxArea) {
            maxArea = area(r);
            best = k;
        }
        k++;
    }
    fclose(f);
    return best;
}

int deleteRect(char fileName[], int number) {
    FILE *f, *t;
    Rect r;
    int k = 1, found = 0;
    char tmpName[100];
    sprintf(tmpName, "%s.tmp", fileName);
    f = fopen(fileName, "rb");
    if (f == NULL) {
        return 0;
    }
    t = fopen(tmpName, "wb");
    if (t == NULL) {
        fclose(f);
        return 0;
    }
    while (fread(&r, sizeof(Rect), 1, f) == 1) {
        if (k == number) {
            found = 1;
        } else {
            fwrite(&r, sizeof(Rect), 1, t);
        }
        k++;
    }
    fclose(f);
    fclose(t);
    if (!found) {
        remove(tmpName);
        return 0;
    }
    if (remove(fileName) != 0) {
        return 0;
    }
    return rename(tmpName, fileName) == 0;
}

int replaceRect(char fileName[], int number, Rect r) {
    FILE *f;
    long size;
    f = fopen(fileName, "r+b");
    if (f == NULL) {
        return 0;
    }
    fseek(f, 0L, SEEK_END);
    size = ftell(f) / (long)sizeof(Rect);
    if (number < 1 || number > size) {
        fclose(f);
        return 0;
    }
    fseek(f, (long)(number - 1) * (long)sizeof(Rect), SEEK_SET);
    fwrite(&r, sizeof(Rect), 1, f);
    fclose(f);
    return 1;
}

int main() {
    char fileName[80];
    Rect r;
    int choice, number;
    setlocale(LC_ALL, "ukr");
    printf("Ім'я файлу: ");
    scanf("%79s", fileName);
    do {
        printf("1 - додати, 2 - показати всі, 3 - найбільша площа, 4 - видалити, 5 - замінити, 0 - вихід: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }
        if (choice == 1) {
            if (inputRect(&r) && appendRect(fileName, r)) {
                printf("Додано\n");
            } else {
                printf("Помилка\n");
            }
        } else if (choice == 2) {
            if (!printRects(fileName)) {
                printf("Файл порожній або не існує\n");
            }
        } else if (choice == 3) {
            number = maxAreaNumber(fileName);
            if (number == 0) {
                printf("Файл порожній або не існує\n");
            } else {
                printf("Найбільша площа у прямокутника з номером %d\n", number);
            }
        } else if (choice == 4) {
            printf("Номер: ");
            if (scanf("%d", &number) == 1 && deleteRect(fileName, number)) {
                printf("Видалено\n");
            } else {
                printf("Помилка\n");
            }
        } else if (choice == 5) {
            printf("Номер: ");
            if (scanf("%d", &number) == 1 && inputRect(&r) && replaceRect(fileName, number, r)) {
                printf("Замінено\n");
            } else {
                printf("Помилка\n");
            }
        }
    } while (choice != 0);
    return 0;
}
