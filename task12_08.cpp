#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <clocale>

using namespace std;

string formatExp(double v) {
    if (isinf(v)) {
        return "inf";
    }
    int digits = v < 1 ? 1 : (int)floor(log10(v)) + 1;
    int p = 5 - digits;
    if (p < 0) {
        p = 0;
    }
    string s;
    while (true) {
        ostringstream os;
        os << fixed << setw(6) << setprecision(p) << v;
        s = os.str();
        if (s.size() <= 6 || p == 0) {
            break;
        }
        p--;
    }
    return s;
}

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
    int count = 0;
    long long x;
    while (in >> x) {
        count++;
    }
    if (!in.eof()) {
        cerr << "Файл містить некоректні дані" << endl;
        return 1;
    }
    in.clear();
    in.seekg(0, ios::beg);
    long long *a = new long long[count];
    for (int i = 0; i < count; i++) {
        in >> a[i];
    }
    in.close();

    ofstream out(name.c_str());
    if (!out) {
        cerr << "Не вдалося записати файл " << name << endl;
        delete[] a;
        return 1;
    }
    for (int i = 0; i < count; i++) {
        out << a[i] << " " << formatExp(exp((double)a[i])) << endl;
    }
    out.close();
    delete[] a;
    cout << "Файл оновлено" << endl;
    return 0;
}
