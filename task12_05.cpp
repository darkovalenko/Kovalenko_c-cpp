#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    const unsigned long long limit = 1000000000000000000ULL;
    string name;
    cout << "Вхідний файл: ";
    cin >> name;
    ifstream in(name.c_str());
    if (!in) {
        cerr << "Файл " << name << " не існує або недоступний" << endl;
        return 1;
    }
    vector<unsigned long long> a;
    unsigned long long x;
    while (in >> x) {
        if (x > limit) {
            cerr << "Число " << x << " більше за 10^18" << endl;
            return 1;
        }
        a.push_back(x);
    }
    if (!in.eof()) {
        cerr << "Файл містить некоректні дані" << endl;
        return 1;
    }
    in.close();
    cout << fixed << setprecision(3);
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        cout << sqrtl((long double)a[i]) << endl;
    }
    return 0;
}
