#include <iostream>
#include <vector>
#include <iomanip>
#include <clocale>

using namespace std;

class Number {
public:
    virtual ~Number() {}
    virtual void print() const = 0;
};

class Real : public Number {
    double value;

public:
    Real(double v = 0) : value(v) {}

    Real operator+(const Real &r) const {
        return Real(value + r.value);
    }

    void print() const {
        cout << value;
    }

    friend istream &operator>>(istream &is, Real &r) {
        return is >> r.value;
    }
};

class Complex : public Number {
    double re;
    double im;

public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {}

    Complex operator+(const Complex &c) const {
        return Complex(re + c.re, im + c.im);
    }

    void print() const {
        cout << re << (im < 0 ? "-" : "+") << (im < 0 ? -im : im) << "i";
    }

    friend istream &operator>>(istream &is, Complex &c) {
        return is >> c.re >> c.im;
    }
};

template <class T> void printBytes(const T &obj) {
    // C-style cast (const unsigned char *)&obj не використовується: запис (T)x сам
    // обирає, який саме cast виконати (static, const чи reinterpret), тому з коду
    // не видно, що відбувається, і компілятор не попереджає про небезпечне перетворення.
    const unsigned char *bytes = reinterpret_cast<const unsigned char *>(&obj);
    cout << hex << setfill('0');
    for (size_t i = 0; i < sizeof(T); ++i) {
        cout << setw(2) << static_cast<int>(bytes[i]) << " ";
    }
    cout << dec << setfill(' ') << endl;
}

void increase(const int &x) {
    const_cast<int &>(x) += 5;
}

int main() {
    setlocale(LC_ALL, "ukr");

    int a, b;
    cout << "Два цілих числа: ";
    cin >> a >> b;
    if (!cin || b == 0) {
        cerr << "Некоректне введення" << endl;
        return 1;
    }

    double ratio = static_cast<double>(a) / b;
    cout << "static_cast<double>: " << a << " / " << b << " = " << ratio << endl;

    cout << "Байти int: ";
    printBytes(a);
    cout << "Байти double: ";
    printBytes(ratio);

    increase(a);
    cout << "const_cast (a не було const): a = " << a << endl;

    int n, m;
    cout << "Кількість дійсних n=";
    cin >> n;
    cout << "Кількість комплексних m=";
    cin >> m;
    if (!cin || n <= 0 || m <= 0) {
        cerr << "Некоректне введення" << endl;
        return 1;
    }

    vector<Real> reals(n);
    vector<Complex> complexes(m);
    cout << "Дійсні числа: ";
    for (int i = 0; i < n; ++i) {
        cin >> reals[i];
    }
    cout << "Комплексні числа (Re Im): ";
    for (int i = 0; i < m; ++i) {
        cin >> complexes[i];
    }
    if (!cin) {
        cerr << "Некоректне введення" << endl;
        return 1;
    }

    Real sumReal;
    for (int i = 0; i < n; ++i) {
        sumReal = sumReal + reals[i];
    }
    Complex sumComplex;
    for (int i = 0; i < m; ++i) {
        sumComplex = sumComplex + complexes[i];
    }
    cout << "Сума дійсних: ";
    sumReal.print();
    cout << endl << "Сума комплексних: ";
    sumComplex.print();
    cout << endl;

    vector<Number *> all;
    all.push_back(&sumReal);
    all.push_back(&sumComplex);
    for (size_t i = 0; i < all.size(); ++i) {
        Complex *c = dynamic_cast<Complex *>(all[i]);
        if (c != nullptr) {
            cout << "Це Complex: ";
            c->print();
            cout << endl;
        } else {
            cout << "Це не Complex" << endl;
        }
    }
    return 0;
}
