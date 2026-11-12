#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    double x, y;
    cout << "x=" << endl;
    cin >> x;
    cout << "y=" << endl;
    cin >> y;
    if (!cin) {
        cerr << "Некоректне введення" << endl;
        return 1;
    }
    double r = pow(x, y);
    if (isnan(r) || isinf(r)) {
        cout << "Результат не визначений або занадто великий" << endl;
        return 1;
    }
    cout << "Десяткове представлення: " << fixed << setprecision(6) << r << endl;
    cout << "Наукове представлення: " << scientific << setprecision(6) << r << endl;
    return 0;
}
