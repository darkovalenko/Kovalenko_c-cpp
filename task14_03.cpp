#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <clocale>

using namespace std;

bool isSeparator(char c) {
    return c == ' ' || c == '\t' || c == '\r' || c == ',' || c == '.' || c == '!' || c == '?';
}

string reverseWord(const string &s) {
    vector<string> chars;
    size_t i = 0;
    while (i < s.size()) {
        unsigned char c = (unsigned char)s[i];
        size_t len = 1;
        if ((c >> 5) == 6) len = 2;
        else if ((c >> 4) == 14) len = 3;
        else if ((c >> 3) == 30) len = 4;
        chars.push_back(s.substr(i, len));
        i += len;
    }
    string r;
    for (int k = (int)chars.size() - 1; k >= 0; k--) {
        r += chars[k];
    }
    return r;
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
    while (getline(in, line)) {
        string res, word;
        for (size_t i = 0; i < line.size(); i++) {
            if (isSeparator(line[i])) {
                res += reverseWord(word);
                word = "";
                res += line[i];
            } else {
                word += line[i];
            }
        }
        res += reverseWord(word);
        out << res << endl;
    }
    in.close();
    out.close();
    cout << "Результат записано у файл " << outName << endl;
    return 0;
}
