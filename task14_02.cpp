#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <clocale>

using namespace std;

bool isArticle(string w) {
    for (size_t i = 0; i < w.size(); i++) {
        w[i] = (char)tolower((unsigned char)w[i]);
    }
    return w == "die" || w == "der" || w == "das";
}

void capitalize(string &w) {
    if (w.empty()) {
        return;
    }
    unsigned char c = (unsigned char)w[0];
    if (c < 128) {
        w[0] = (char)toupper(c);
    } else if (c == 0xC3 && w.size() > 1) {
        unsigned char d = (unsigned char)w[1];
        if (d >= 0xA0 && d <= 0xBE && d != 0xB7) {
            w[1] = (char)(d - 0x20);
        }
    }
}

int main() {
    setlocale(LC_ALL, "ukr");
    string inName, outName, line;
    cout << "Вхідний файл: ";
    cin >> inName;
    cout << "Вихідний файл: ";
    cin >> outName;
    ifstream in(inName.c_str());
    if (!in) {
        cerr << "Файл " << inName << " не існує або недоступний" << endl;
        return 1;
    }
    ofstream out(outName.c_str());
    if (!out) {
        cerr << "Не вдалося створити файл " << outName << endl;
        return 1;
    }
    bool cap = false;
    while (getline(in, line)) {
        string res;
        size_t i = 0;
        while (i < line.size()) {
            if (line[i] == ' ') {
                res += ' ';
                i++;
                continue;
            }
            size_t j = i;
            while (j < line.size() && line[j] != ' ') {
                j++;
            }
            string w = line.substr(i, j - i);
            if (cap) {
                capitalize(w);
            }
            cap = isArticle(w);
            res += w;
            i = j;
        }
        out << res << endl;
    }
    in.close();
    out.close();
    cout << "Результат записано у файл " << outName << endl;
    return 0;
}
