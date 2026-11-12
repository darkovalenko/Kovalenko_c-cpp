#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <clocale>

using namespace std;

bool isEmptyLine(const string &s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (!isspace((unsigned char)s[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "ukr");
    int n;
    string name, line;
    cout << "N=";
    cin >> n;
    if (!cin || n <= 0) {
        cerr << "Некоректне N" << endl;
        return 1;
    }
    cout << "Файл: ";
    cin >> name;
    ifstream in(name.c_str());
    if (!in) {
        cerr << "Файл " << name << " не існує або недоступний" << endl;
        return 1;
    }
    vector<string> result;
    int count = 0;
    bool removed = false;
    while (getline(in, line)) {
        if (isEmptyLine(line)) {
            result.push_back(line);
            continue;
        }
        count++;
        if (count % n == 0) {
            removed = true;
        } else {
            result.push_back(line);
        }
    }
    in.close();
    if (!removed) {
        cout << "Рядків з потрібними номерами немає, файл без змін" << endl;
        return 0;
    }
    ofstream out(name.c_str());
    if (!out) {
        cerr << "Не вдалося записати файл " << name << endl;
        return 1;
    }
    for (size_t i = 0; i < result.size(); i++) {
        out << result[i] << endl;
    }
    out.close();
    cout << "Файл оновлено" << endl;
    return 0;
}
