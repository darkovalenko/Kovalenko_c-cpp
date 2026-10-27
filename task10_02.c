#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char letter;
    int number;
} ChessSquare;

int inputChessSquare(ChessSquare *s) {
    char letter;
    int number;
    if (scanf(" %c%d", &letter, &number) != 2) return 0;
    if (letter < 'a' || letter > 'h' || number < 1 || number > 8) return 0;
    s->letter = letter;
    s->number = number;
    return 1;
}

int queenCanMove(ChessSquare from, ChessSquare to) {
    int dx = abs(from.letter - to.letter);
    int dy = abs(from.number - to.number);
    if (dx == 0 && dy == 0) {
        return 0;
    }
    return dx == 0 || dy == 0 || dx == dy;
}

int main() {
    ChessSquare from, to;
    setlocale(LC_ALL, "ukr");
    printf("Початкове поле (наприклад, a5): ");
    if (!inputChessSquare(&from)) {
        printf("Некоректне поле\n");
        return 1;
    }
    printf("Кінцеве поле (наприклад, b8): ");
    if (!inputChessSquare(&to)) {
        printf("Некоректне поле\n");
        return 1;
    }
    if (queenCanMove(from, to)) {
        printf("Ферзь може перейти за один хід\n");
    } else {
        printf("Ферзь не може перейти за один хід\n");
    }
    return 0;
}
