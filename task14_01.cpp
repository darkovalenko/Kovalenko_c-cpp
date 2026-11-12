#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    string name;
    cout << "Файл: ";
    cin >> name;
    ifstream in(name.c_str());
    if (!in) {
        cerr << "Файл " << name << " не існує або недоступний" << endl;
        return 1;
    }
    string expr, line;
    while (getline(in, line)) {
        for (size_t i = 0; i < line.size(); i++) {
            if (!isspace((unsigned char)line[i])) {
                expr += line[i];
            }
        }
    }
    in.close();

    size_t i = 0;
    long long result = 0;
    int sign = 1;
    int terms = 0;
    if (i < expr.size() && (expr[i] == '+' || expr[i] == '-')) {
        if (expr[i] == '-') {
            sign = -1;
        }
        i++;
    }
    while (true) {
        if (i >= expr.size() || !isdigit((unsigned char)expr[i])) {
            cerr << "Некоректний вираз у позиції " << i + 1 << endl;
            return 1;
        }
        long long d = 0;
        while (i < expr.size() && isdigit((unsigned char)expr[i])) {
            d = d * 10 + (expr[i] - '0');
            i++;
        }
        result = result + sign * d;
        terms++;
        if (i == expr.size()) {
            break;
        }
        if (expr[i] != '+' && expr[i] != '-') {
            cerr << "Некоректний вираз у позиції " << i + 1 << endl;
            return 1;
        }
        sign = expr[i] == '+' ? 1 : -1;
        i++;
    }
    cout << "Кількість доданків: " << terms << endl;
    cout << "Значення виразу: " << result << endl;
    return 0;
}
