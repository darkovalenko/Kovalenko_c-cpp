#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
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
    string text((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();
    for (size_t i = 0; i < text.size(); i++) {
        text[i] = (char)tolower((unsigned char)text[i]);
    }

    vector<int> opened;
    int line = 1;
    size_t i = 0;
    while (i < text.size()) {
        if (text.compare(i, 4, "<td>") == 0) {
            opened.push_back(line);
            i += 4;
        } else if (text.compare(i, 5, "</td>") == 0) {
            if (opened.empty()) {
                cout << "Помилка: закритий тег </td> у рядку " << line << " не має відкритого" << endl;
                return 0;
            }
            opened.pop_back();
            i += 5;
        } else {
            if (text[i] == '\n') {
                line++;
            }
            i++;
        }
    }
    if (!opened.empty()) {
        cout << "Помилка: відкритий тег <td> у рядку " << opened.back() << " не закритий" << endl;
        return 0;
    }
    cout << "Теги <td> розставлені правильно" << endl;
    return 0;
}
