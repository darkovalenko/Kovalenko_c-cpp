#include <iostream>
#include <cctype>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    int n;
    cout << "n=";
    cin >> n;
    if (!cin || n <= 0) {
        cerr << "Некоректне n" << endl;
        return 1;
    }
    unsigned long long *a = new unsigned long long[n];
    unsigned long long sum = 0;
    char c;
    cout << "Введіть " << 10 * n << " цифр" << endl;
    for (int i = 0; i < n; i++) {
        a[i] = 0;
        for (int j = 0; j < 10; j++) {
            cin >> c;
            if (!cin || !isdigit(c)) {
                cerr << "Некоректне введення" << endl;
                delete[] a;
                return 1;
            }
            a[i] = a[i] * 10 + (c - '0');
        }
    }
    for (int i = 0; i < n; i++) {
        sum = sum + a[i];
    }
    cout << "Сума = " << sum << endl;
    delete[] a;
    return 0;
}
