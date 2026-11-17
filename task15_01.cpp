#include <iostream>
#include <cmath>
#include <stdexcept>
#include <clocale>

using namespace std;

class Rational {
    int nominator;
    unsigned int denominator;

    static unsigned long long gcd(unsigned long long a, unsigned long long b) {
        while (b != 0) {
            unsigned long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    void reduce() {
        unsigned long long absN = nominator < 0 ? (unsigned long long)(-(long long)nominator) : (unsigned long long)nominator;
        unsigned long long g = gcd(absN, denominator);
        if (g > 1) {
            nominator = (int)(nominator / (long long)g);
            denominator = (unsigned int)(denominator / g);
        }
    }

    static Rational make(long long n, unsigned long long d) {
        unsigned long long absN = n < 0 ? (unsigned long long)(-n) : (unsigned long long)n;
        unsigned long long g = gcd(absN, d);
        Rational r;
        r.nominator = (int)(n / (long long)g);
        r.denominator = (unsigned int)(d / g);
        return r;
    }

public:
    Rational() : nominator(1), denominator(1) {}

    Rational(int n, unsigned int d) : nominator(n), denominator(d) {
        if (denominator == 0) {
            cerr << "Знаменник не може бути нулем, встановлено 1" << endl;
            denominator = 1;
        }
        reduce();
    }

    int getNominator() const {
        return nominator;
    }

    unsigned int getDenominator() const {
        return denominator;
    }

    void setNominator(int n) {
        nominator = n;
        reduce();
    }

    bool setDenominator(unsigned int d) {
        if (d == 0) {
            return false;
        }
        denominator = d;
        reduce();
        return true;
    }

    double toDouble() const {
        return (double)nominator / denominator;
    }

    void input() {
        int n;
        long long d;
        cout << "Чисельник: ";
        cin >> n;
        do {
            cout << "Знаменник (натуральне число): ";
            cin >> d;
            if (!cin) {
                return;
            }
        } while (d <= 0 || d > 4294967295LL);
        nominator = n;
        denominator = (unsigned int)d;
        reduce();
    }

    void print() const {
        if (denominator == 1) {
            cout << nominator;
        } else {
            cout << nominator << "/" << denominator;
        }
    }

    Rational add(const Rational &b) const {
        return make((long long)nominator * b.denominator + (long long)b.nominator * denominator,
                    (unsigned long long)denominator * b.denominator);
    }

    Rational multiply(const Rational &b) const {
        return make((long long)nominator * b.nominator, (unsigned long long)denominator * b.denominator);
    }

    Rational operator+(const Rational &b) const {
        return add(b);
    }

    Rational operator-(const Rational &b) const {
        return make((long long)nominator * b.denominator - (long long)b.nominator * denominator,
                    (unsigned long long)denominator * b.denominator);
    }

    Rational operator*(const Rational &b) const {
        return multiply(b);
    }

    Rational operator/(const Rational &b) const {
        if (b.nominator == 0) {
            throw invalid_argument("Ділення на нуль");
        }
        long long n = (long long)nominator * b.denominator;
        unsigned long long d = (unsigned long long)denominator * (b.nominator < 0 ? -(long long)b.nominator : b.nominator);
        if (b.nominator < 0) {
            n = -n;
        }
        return make(n, d);
    }

    Rational operator-() const {
        return make(-(long long)nominator, denominator);
    }

    Rational &operator+=(const Rational &b) {
        *this = *this + b;
        return *this;
    }

    Rational &operator*=(const Rational &b) {
        *this = *this * b;
        return *this;
    }

    bool operator==(const Rational &b) const {
        return nominator == b.nominator && denominator == b.denominator;
    }

    bool operator!=(const Rational &b) const {
        return !(*this == b);
    }

    bool operator<(const Rational &b) const {
        return (long long)nominator * b.denominator < (long long)b.nominator * denominator;
    }

    bool operator>(const Rational &b) const {
        return b < *this;
    }

    bool operator<=(const Rational &b) const {
        return !(b < *this);
    }

    bool operator>=(const Rational &b) const {
        return !(*this < b);
    }

    friend ostream &operator<<(ostream &os, const Rational &r) {
        if (r.denominator == 1) {
            os << r.nominator;
        } else {
            os << r.nominator << "/" << r.denominator;
        }
        return os;
    }

    friend istream &operator>>(istream &is, Rational &r) {
        int n;
        long long d;
        is >> n >> d;
        if (is && (d <= 0 || d > 4294967295LL)) {
            is.setstate(ios::failbit);
        }
        if (is) {
            r.nominator = n;
            r.denominator = (unsigned int)d;
            r.reduce();
        }
        return is;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");

    Rational a, b;
    cout << "Перше число" << endl;
    a.input();
    cout << "Друге число" << endl;
    b.input();
    if (!cin) {
        cerr << "Некоректне введення" << endl;
        return 1;
    }
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    if (b != Rational(0, 1)) {
        cout << a << " / " << b << " = " << a / b << endl;
    }
    cout << a << (a < b ? " < " : (a > b ? " > " : " = ")) << b << endl;

    int n;
    cout << "N=";
    cin >> n;
    if (!cin || n <= 0) {
        cerr << "Некоректне N" << endl;
        return 1;
    }
    Rational *arr = new Rational[n];
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "]" << endl;
        arr[i].input();
        if (!cin) {
            cerr << "Некоректне введення" << endl;
            delete[] arr;
            return 1;
        }
    }
    Rational minimum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    cout << "Найменше раціональне число: " << minimum << endl;
    delete[] arr;

    Rational sum(1, 1);
    int k = 2;
    while (true) {
        Rational term(1, k * k);
        if (term.toDouble() < 0.01) {
            break;
        }
        if (k % 2 == 0) {
            sum = sum - term;
        } else {
            sum = sum + term;
        }
        k++;
    }
    double target = acos(-1.0) * acos(-1.0) / 12;
    cout << "Сума ряду: " << sum << " = " << sum.toDouble() << endl;
    cout << "pi^2/12 = " << target << endl;
    if (fabs(sum.toDouble() - target) < 0.01) {
        cout << "Ряд збігається до pi^2/12 з точністю 0.01" << endl;
    } else {
        cout << "Ряд не збігається до pi^2/12 з точністю 0.01" << endl;
    }
    return 0;
}
