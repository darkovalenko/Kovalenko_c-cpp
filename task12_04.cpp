#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
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
    int *m = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "m[" << i << "]=";
        cin >> m[i];
        if (!cin) {
            cerr << "Некоректне введення" << endl;
            delete[] m;
            return 1;
        }
    }
    string inName, outName;
    cout << "Вхідний файл: ";
    cin >> inName;
    cout << "Вихідний файл: ";
    cin >> outName;

    ifstream in(inName.c_str());
    if (!in) {
        cerr << "Файл " << inName << " не існує або недоступний" << endl;
        delete[] m;
        return 1;
    }
    double *x = new double[n];
    for (int i = 0; i < n; i++) {
        in >> x[i];
        if (!in) {
            cerr << "Файл некоректний: не вдалося прочитати " << n << " дійсних чисел" << endl;
            delete[] m;
            delete[] x;
            return 1;
        }
    }
    in.close();

    ofstream out(outName.c_str());
    if (!out) {
        cerr << "Не вдалося створити файл " << outName << endl;
        delete[] m;
        delete[] x;
        return 1;
    }
    for (int i = 0; i < n; i++) {
        out << setprecision(10) << pow(x[i], m[i]) << endl;
    }
    out.close();
    cout << "Результат записано у файл " << outName << endl;
    delete[] m;
    delete[] x;
    return 0;
}
