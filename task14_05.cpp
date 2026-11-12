#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <clocale>

using namespace std;

bool createFile(const string &name, int n) {
    ofstream out(name.c_str());
    if (!out) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        string surname, first, group;
        int k;
        cout << "Студент " << i + 1 << ": прізвище ім'я група кількість_оцінок" << endl;
        cin >> surname >> first >> group >> k;
        if (!cin || k <= 0) {
            return false;
        }
        out << surname << " " << first << " " << group << " ";
        cout << "Оцінки: ";
        for (int j = 0; j < k; j++) {
            int g;
            cin >> g;
            if (!cin) {
                return false;
            }
            out << g;
            if (j < k - 1) {
                out << ",";
            }
        }
        out << endl;
    }
    out.close();
    return true;
}

bool worstStudent(const string &name, string &worst, double &worstAvg) {
    ifstream in(name.c_str());
    if (!in) {
        return false;
    }
    string line;
    bool found = false;
    while (getline(in, line)) {
        for (size_t i = 0; i < line.size(); i++) {
            if (line[i] == ',') {
                line[i] = ' ';
            }
        }
        istringstream is(line);
        string surname, first, group;
        if (!(is >> surname >> first >> group)) {
            continue;
        }
        int g, count = 0;
        double sum = 0;
        while (is >> g) {
            sum += g;
            count++;
        }
        if (count == 0) {
            continue;
        }
        double avg = sum / count;
        if (!found || avg < worstAvg) {
            worst = surname;
            worstAvg = avg;
            found = true;
        }
    }
    in.close();
    return found;
}

int main() {
    setlocale(LC_ALL, "ukr");
    string name, worst;
    double avg;
    int n;
    cout << "Ім'я файлу: ";
    cin >> name;
    cout << "N=";
    cin >> n;
    if (!cin || n <= 0) {
        cerr << "Некоректне N" << endl;
        return 1;
    }
    if (!createFile(name, n)) {
        cerr << "Помилка створення файлу або некоректне введення" << endl;
        return 1;
    }
    if (!worstStudent(name, worst, avg)) {
        cerr << "У файлі немає даних про студентів" << endl;
        return 1;
    }
    cout << "Найгірша середня оцінка у студента " << worst << " (" << avg << ")" << endl;
    return 0;
}
