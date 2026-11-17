#include <iostream>
#include <string>
#include <cstring>
#include <clocale>

using namespace std;

namespace MyLib {

    class Rational {
        long long nominator;
        long long denominator;

        static long long gcd(long long a, long long b) {
            if (a < 0) {
                a = -a;
            }
            while (b != 0) {
                long long t = a % b;
                a = b;
                b = t;
            }
            return a;
        }

        void reduce() {
            long long g = gcd(nominator, denominator);
            if (g > 1) {
                nominator /= g;
                denominator /= g;
            }
        }

    public:
        Rational(long long n = 0, long long d = 1) : nominator(n), denominator(d) {
            if (denominator == 0) {
                cerr << "Знаменник не може бути нулем, встановлено 1" << endl;
                denominator = 1;
            }
            if (denominator < 0) {
                nominator = -nominator;
                denominator = -denominator;
            }
            reduce();
        }

        bool operator<(const Rational &b) const {
            return nominator * b.denominator < b.nominator * denominator;
        }

        bool operator>(const Rational &b) const {
            return b < *this;
        }

        bool operator==(const Rational &b) const {
            return nominator == b.nominator && denominator == b.denominator;
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
            long long n, d;
            is >> n >> d;
            if (is && d == 0) {
                is.setstate(ios::failbit);
            }
            if (is) {
                r = Rational(n, d);
            }
            return is;
        }
    };

    template <class T> const T &maximum(const T &a, const T &b) {
        return (a < b) ? b : a;
    }

    const char *maximum(const char *a, const char *b) {
        return (strcmp(a, b) < 0) ? b : a;
    }

}

int main() {
    setlocale(LC_ALL, "ukr");

    int i1, i2;
    cout << "Два цілих числа: ";
    cin >> i1 >> i2;
    double d1, d2;
    cout << "Два дійсних числа: ";
    cin >> d1 >> d2;
    char c1, c2;
    cout << "Два символи: ";
    cin >> c1 >> c2;
    string s1, s2;
    cout << "Два рядки: ";
    cin >> s1 >> s2;
    MyLib::Rational r1, r2;
    cout << "Перший дріб (чисельник знаменник): ";
    cin >> r1;
    cout << "Другий дріб (чисельник знаменник): ";
    cin >> r2;
    if (!cin) {
        cerr << "Некоректне введення" << endl;
        return 1;
    }

    cout << "int: " << MyLib::maximum(i1, i2) << endl;
    cout << "double: " << MyLib::maximum(d1, d2) << endl;
    cout << "char: " << MyLib::maximum(c1, c2) << endl;
    cout << "string: " << MyLib::maximum(s1, s2) << endl;
    cout << "Rational: " << MyLib::maximum(r1, r2) << endl;
    cout << "const char*: " << MyLib::maximum("apple", "pear") << endl;
    cout << "long: " << MyLib::maximum(100000L, 99999L) << endl;
    cout << "float: " << MyLib::maximum(1.5f, 2.5f) << endl;
    return 0;
}
