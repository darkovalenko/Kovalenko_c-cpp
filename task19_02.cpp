#include <iostream>
#include <vector>
#include <cmath>
#include <clocale>

using namespace std;

bool inputVector(vector<double> &v, size_t d) {
    v.assign(d, 0.0);
    for (size_t i = 0; i < d; ++i) {
        cin >> v[i];
        if (!cin) {
            return false;
        }
    }
    return true;
}

double norm(const vector<double> &v) {
    double s = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        s += v[i] * v[i];
    }
    return sqrt(s);
}

int main() {
    setlocale(LC_ALL, "ukr");

    int d, n;
    cout << "Розмірність векторів d=";
    cin >> d;
    cout << "Кількість векторів n=";
    cin >> n;
    if (!cin || d <= 0 || n <= 0) {
        cerr << "d і n мають бути натуральними числами" << endl;
        return 1;
    }

    vector<vector<double> > vectors;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        vector<double> v;
        cout << "Вектор " << i + 1 << " (" << d << " координат): ";
        if (!inputVector(v, d)) {
            cerr << "Некоректне введення" << endl;
            return 1;
        }
        vectors.push_back(v);
    }
    for (size_t i = 0; i < vectors.size(); ++i) {
        double len = norm(vectors[i]);
        cout << "||v" << i + 1 << "|| = " << len << endl;
        sum += len;
    }
    cout << "Сума норм: " << sum << endl;
    return 0;
}
