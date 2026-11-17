#include <iostream>
#include <vector>
#include <list>
#include <clocale>

using namespace std;

int rowMax(const list<int> &row) {
    list<int>::const_iterator it = row.begin();
    int m = *it;
    for (; it != row.end(); ++it) {
        if (*it > m) {
            m = *it;
        }
    }
    return m;
}

void printMatrix(const vector<list<int> > &a) {
    for (size_t i = 0; i < a.size(); ++i) {
        for (list<int>::const_iterator it = a[i].begin(); it != a[i].end(); ++it) {
            cout << *it << "\t";
        }
        cout << "  [max = " << rowMax(a[i]) << "]" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ukr");

    int n, m;
    cout << "n=";
    cin >> n;
    cout << "m=";
    cin >> m;
    if (!cin || n <= 0 || m <= 0 || n >= 100 || m >= 100) {
        cerr << "n і m мають бути натуральними числами, меншими за 100" << endl;
        return 1;
    }

    vector<list<int> > a(n);
    for (int i = 0; i < n; ++i) {
        cout << "Рядок " << i + 1 << ": ";
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            if (!cin) {
                cerr << "Некоректне введення" << endl;
                return 1;
            }
            a[i].push_back(x);
        }
    }

    cout << "Початкова матриця:" << endl;
    printMatrix(a);

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (rowMax(a[j]) < rowMax(a[j + 1])) {
                a[j].swap(a[j + 1]);
            }
        }
    }

    cout << "Матриця після впорядкування рядків:" << endl;
    printMatrix(a);
    return 0;
}
