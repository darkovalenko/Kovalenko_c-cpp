#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    const int width = 7;
    int n;
    cout << "n=";
    cin >> n;
    if (!cin || n <= 0) {
        cerr << "Некоректне n" << endl;
        return 1;
    }
    string line(n * width, '+');
    cout << line << endl;
    for (int i = 1; i <= n; i++) {
        cout << setw(width) << i;
    }
    cout << endl << line << endl;
    for (int i = 1; i <= n; i++) {
        int r = (int)(sqrt((double)i) + 0.5);
        if (r * r == i) {
            cout << setw(width) << r;
        } else {
            cout << setw(width) << fixed << setprecision(2) << sqrt((double)i);
        }
    }
    cout << endl << line << endl;
    return 0;
}
