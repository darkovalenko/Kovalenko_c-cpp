#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <clocale>

using namespace std;

int parseInteger(const string &s, int &value) {
    size_t i = 0;
    bool negative = false;
    if (s[0] == '+' || s[0] == '-') {
        negative = (s[0] == '-');
        i = 1;
    }
    if (i == s.size()) {
        return 1;
    }
    long long result = 0;
    for (; i < s.size(); ++i) {
        if (s[i] < '0' || s[i] > '9') {
            return 1;
        }
        result = result * 10 + (s[i] - '0');
        if (result > (long long)INT_MAX + 1) {
            return 2;
        }
    }
    if (negative) {
        result = -result;
    }
    if (result > INT_MAX || result < INT_MIN) {
        return 2;
    }
    value = (int)result;
    return 0;
}

int main() {
    setlocale(LC_ALL, "ukr");

    string fileName;
    cout << "Ім'я текстового файлу: ";
    cin >> fileName;
    ifstream in(fileName.c_str());
    if (!in) {
        cerr << "Не вдалося відкрити файл " << fileName << endl;
        return 1;
    }

    vector<int> V;
    string token;
    int position = 0;
    int errors = 0;
    while (in >> token) {
        ++position;
        int value;
        int status = parseInteger(token, value);
        if (status == 0) {
            V.push_back(value);
        } else if (status == 1) {
            cout << "Елемент №" << position << " \"" << token << "\" не є цілим числом" << endl;
            ++errors;
        } else {
            cout << "Елемент №" << position << " \"" << token << "\" виходить за межі типу int" << endl;
            ++errors;
        }
    }

    if (position == 0) {
        cout << "Файл порожній" << endl;
        return 0;
    }
    if (errors > 0) {
        cout << "Некоректних елементів: " << errors << endl;
    }
    cout << "Вектор V (" << V.size() << " елементів): ";
    for (size_t i = 0; i < V.size(); ++i) {
        cout << V[i] << " ";
    }
    cout << endl;
    return 0;
}
