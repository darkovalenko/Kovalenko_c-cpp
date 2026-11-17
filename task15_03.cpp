#include <iostream>
#include <fstream>
#include <clocale>

using namespace std;

class Polynomial {
    int n;
    double *coef;

public:
    Polynomial(int size) : n(size), coef(new double[size]) {
        for (int i = 0; i < n; i++) {
            coef[i] = 0;
        }
    }

    Polynomial(int size, const double *values) : n(size), coef(new double[size]) {
        fill(values);
    }

    Polynomial(const Polynomial &p) : n(p.n), coef(new double[p.n]) {
        for (int i = 0; i < n; i++) {
            coef[i] = p.coef[i];
        }
    }

    ~Polynomial() {
        delete[] coef;
    }

    Polynomial &operator=(const Polynomial &p) {
        if (this != &p) {
            double *tmp = new double[p.n];
            for (int i = 0; i < p.n; i++) {
                tmp[i] = p.coef[i];
            }
            delete[] coef;
            coef = tmp;
            n = p.n;
        }
        return *this;
    }

    int size() const {
        return n;
    }

    void fill(const double *values) {
        for (int i = 0; i < n; i++) {
            coef[i] = values[i];
        }
    }

    bool setCoef(int i, double value) {
        if (i < 0 || i >= n) {
            return false;
        }
        coef[i] = value;
        return true;
    }

    friend ostream &operator<<(ostream &os, const Polynomial &p) {
        for (int i = 0; i < p.n; i++) {
            if (i > 0) {
                os << " + ";
            }
            os << p.coef[i] << "*x^" << i;
        }
        return os;
    }

    friend istream &operator>>(istream &is, Polynomial &p) {
        for (int i = 0; i < p.n; i++) {
            cout << "Коефіцієнт при x^" << i << ": ";
            is >> p.coef[i];
        }
        return is;
    }

    friend bool saveBinary(const Polynomial &p, const char *fileName) {
        ofstream out(fileName, ios::binary);
        if (!out) {
            return false;
        }
        out.write((const char *)&p.n, sizeof(int));
        out.write((const char *)p.coef, p.n * sizeof(double));
        return (bool)out;
    }

    friend bool loadBinary(Polynomial &p, const char *fileName) {
        ifstream in(fileName, ios::binary);
        if (!in) {
            return false;
        }
        int size;
        in.read((char *)&size, sizeof(int));
        if (!in || size <= 0) {
            return false;
        }
        double *tmp = new double[size];
        in.read((char *)tmp, size * sizeof(double));
        if (!in) {
            delete[] tmp;
            return false;
        }
        delete[] p.coef;
        p.coef = tmp;
        p.n = size;
        return true;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    int size;
    cout << "Кількість коефіцієнтів N=";
    cin >> size;
    if (!cin || size <= 0) {
        cerr << "Некоректне N" << endl;
        return 1;
    }
    Polynomial p(size);
    cin >> p;
    if (!cin) {
        cerr << "Некоректне введення" << endl;
        return 1;
    }
    cout << "P(x) = " << p << endl;

    double v[3] = {1, 2, 3};
    Polynomial q(3, v);
    q.setCoef(1, 5);
    cout << "Q(x) = " << q << endl;

    Polynomial c(p);
    cout << "Копія P: " << c << endl;
    c = q;
    cout << "Після присвоєння: " << c << endl;

    if (!saveBinary(p, "poly.bin")) {
        cerr << "Помилка запису у файл" << endl;
        return 1;
    }
    Polynomial r(1);
    if (!loadBinary(r, "poly.bin")) {
        cerr << "Помилка читання файлу" << endl;
        return 1;
    }
    cout << "Прочитано з файлу: " << r << endl;
    return 0;
}
