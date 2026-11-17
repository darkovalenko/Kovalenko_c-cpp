#include <iostream>
#include <string>
#include <vector>
#include <clocale>

using namespace std;

namespace MyLib {

    template <class T> T sum(T *x, size_t n) {
        T result = T();
        for (size_t i = 0; i < n; ++i) {
            result = result + x[i];
        }
        return result;
    }

    string sum(char *x, size_t n) {
        string result;
        for (size_t i = 0; i < n; ++i) {
            result += x[i];
        }
        return result;
    }

    template <class T> vector<T> sum(T **x, size_t n) {
        vector<T> result;
        for (size_t i = 0; i < n; ++i) {
            if (x[i] != 0) {
                result.push_back(*x[i]);
            }
        }
        return result;
    }

    template <class T> void printVector(const vector<T> &v) {
        cout << "{";
        for (size_t i = 0; i < v.size(); ++i) {
            if (i > 0) {
                cout << ",";
            }
            cout << v[i];
        }
        cout << "}";
    }

}

int main() {
    setlocale(LC_ALL, "ukr");

    int v1[] = {1, 2, 3};
    cout << "int: " << MyLib::sum(v1, 3) << endl;

    double v2[] = {1, 2, 3};
    cout << "double: " << MyLib::sum(v2, 3) << endl;

    string v3[] = {"a", "bc", "def"};
    cout << "string: " << MyLib::sum(v3, 3) << endl;

    char v4[] = {'a', 'b', 'c'};
    cout << "char: " << MyLib::sum(v4, 3) << endl;

    int a1[] = {1, 4};
    int a2[] = {2};
    int a3[] = {3};
    int *v5[] = {a1, a2, a3};
    cout << "int*: ";
    MyLib::printVector(MyLib::sum(v5, 3));
    cout << endl;

    int *v6[] = {a1, 0, a3, 0};
    cout << "int* з нульовими вказівниками: ";
    MyLib::printVector(MyLib::sum(v6, 4));
    cout << endl;

    double b1 = 1.5, b2 = 2.5;
    double *v7[] = {&b1, &b2};
    cout << "double*: ";
    MyLib::printVector(MyLib::sum(v7, 2));
    cout << endl;
    return 0;
}
