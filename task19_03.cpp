#include <iostream>
#include <list>
#include <string>
#include <sstream>
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

        Rational operator+(const Rational &b) const {
            return Rational(nominator * b.denominator + b.nominator * denominator, denominator * b.denominator);
        }

        Rational operator*(const Rational &b) const {
            return Rational(nominator * b.nominator, denominator * b.denominator);
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

    template <class T> class Polynomial {
        list<T> coef;

    public:
        Polynomial() {}

        bool input(istream &is) {
            int n;
            if (!(is >> n) || n < 0 || n > 1000) {
                return false;
            }
            coef.clear();
            for (int i = 0; i <= n; ++i) {
                T c;
                if (!(is >> c)) {
                    return false;
                }
                coef.push_back(c);
            }
            return true;
        }

        void print(ostream &os) const {
            size_t i = 0;
            for (typename list<T>::const_iterator it = coef.begin(); it != coef.end(); ++it, ++i) {
                if (i > 0) {
                    os << " + ";
                }
                ostringstream s;
                s << *it;
                string text = s.str();
                if (text.find('/') != string::npos || text.find('-') != string::npos) {
                    os << "(" << text << ")";
                } else {
                    os << text;
                }
                if (i > 0) {
                    os << "*x^" << i;
                }
            }
            if (coef.empty()) {
                os << "0";
            }
        }

        Polynomial operator+(const Polynomial &p) const {
            Polynomial result;
            typename list<T>::const_iterator a = coef.begin();
            typename list<T>::const_iterator b = p.coef.begin();
            while (a != coef.end() || b != p.coef.end()) {
                T s = T(0);
                if (a != coef.end()) {
                    s = s + *a;
                    ++a;
                }
                if (b != p.coef.end()) {
                    s = s + *b;
                    ++b;
                }
                result.coef.push_back(s);
            }
            return result;
        }

        Polynomial operator*(const Polynomial &p) const {
            Polynomial result;
            if (coef.empty() || p.coef.empty()) {
                return result;
            }
            result.coef.assign(coef.size() + p.coef.size() - 1, T(0));
            typename list<T>::iterator start = result.coef.begin();
            for (typename list<T>::const_iterator a = coef.begin(); a != coef.end(); ++a, ++start) {
                typename list<T>::iterator r = start;
                for (typename list<T>::const_iterator b = p.coef.begin(); b != p.coef.end(); ++b, ++r) {
                    *r = *r + (*a) * (*b);
                }
            }
            return result;
        }

        T value(const T &x) const {
            T result = T(0);
            for (typename list<T>::const_reverse_iterator it = coef.rbegin(); it != coef.rend(); ++it) {
                result = result * x + *it;
            }
            return result;
        }

        friend ostream &operator<<(ostream &os, const Polynomial &p) {
            p.print(os);
            return os;
        }
    };

    template <class T> bool demo(const string &name, const string &hint) {
        cout << "--- " << name << " ---" << endl;
        cout << "Формат: степінь, потім коефіцієнти від a0 до an" << hint << endl;
        Polynomial<T> p, q;
        T x;
        cout << "P: ";
        if (!p.input(cin)) {
            return false;
        }
        cout << "Q: ";
        if (!q.input(cin)) {
            return false;
        }
        cout << "x: ";
        if (!(cin >> x)) {
            return false;
        }
        cout << "P(x) = " << p << endl;
        cout << "Q(x) = " << q << endl;
        cout << "P+Q = " << p + q << endl;
        cout << "P*Q = " << p * q << endl;
        cout << "P(" << x << ") = " << p.value(x) << endl;
        cout << "Q(" << x << ") = " << q.value(x) << endl;
        return true;
    }

}

int main() {
    setlocale(LC_ALL, "ukr");

    if (!MyLib::demo<int>("Цілі числа", "")
        || !MyLib::demo<double>("Дійсні числа", "")
        || !MyLib::demo<MyLib::Rational>("Раціональні дроби", " (кожен коефіцієнт - чисельник і знаменник)")) {
        cerr << "Некоректне введення" << endl;
        return 1;
    }
    return 0;
}
