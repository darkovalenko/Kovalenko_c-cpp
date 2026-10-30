#include <stdio.h>
#include <locale.h>

#define SURNAME_LEN 30

typedef struct {
    char surname[SURNAME_LEN];
    int things;
    double weight;
} Passenger;

int createFile(char fileName[]) {
    FILE *out;
    Passenger p;
    int ans;
    out = fopen(fileName, "wb");
    if (out == NULL) {
        return 0;
    }
    do {
        printf("Прізвище: ");
        if (scanf("%29s", p.surname) != 1) break;
        printf("Кількість речей: ");
        if (scanf("%d", &p.things) != 1 || p.things < 0) break;
        printf("Загальна вага (кг): ");
        if (scanf("%lf", &p.weight) != 1 || p.weight < 0) break;
        fwrite(&p, sizeof(Passenger), 1, out);
        printf("Продовжити (1 так, 0 ні)? ");
        if (scanf("%d", &ans) != 1) break;
    } while (ans);
    fclose(out);
    return 1;
}

int printFile(char fileName[]) {
    FILE *in;
    Passenger p;
    int k = 1;
    in = fopen(fileName, "rb");
    if (in == NULL) {
        return 0;
    }
    while (fread(&p, sizeof(Passenger), 1, in) == 1) {
        printf("%3d %-30s %5d %8.2f\n", k, p.surname, p.things, p.weight);
        k++;
    }
    fclose(in);
    return 1;
}

int findPassenger(char fileName[], Passenger *res) {
    FILE *in;
    Passenger p;
    int k = 1, best = 0;
    in = fopen(fileName, "rb");
    if (in == NULL) {
        return -1;
    }
    while (fread(&p, sizeof(Passenger), 1, in) == 1) {
        if (best == 0 || p.things > res->things || (p.things == res->things && p.weight < res->weight)) {
            *res = p;
            best = k;
        }
        k++;
    }
    fclose(in);
    return best;
}

int main() {
    char fileName[80];
    Passenger p;
    int number;
    setlocale(LC_ALL, "ukr");
    printf("Ім'я файлу: ");
    scanf("%79s", fileName);
    if (!createFile(fileName)) {
        printf("Помилка створення файлу\n");
        return 1;
    }
    printFile(fileName);
    number = findPassenger(fileName, &p);
    if (number <= 0) {
        printf("Файл порожній\n");
        return 1;
    }
    printf("Пасажир №%d: %s, речей: %d, вага: %.2f кг\n", number, p.surname, p.things, p.weight);
    return 0;
}
