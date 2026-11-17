#include <iostream>
#include <string>
#include <clocale>

using namespace std;

namespace MyLib {

    template <class T> class Array {
        size_t size;
        T *data;

    public:
        Array(size_t n = 0);
        Array(const T *source, size_t n);
        Array(const Array &a);
        ~Array();
        Array &operator=(const Array &a);
        T &operator[](size_t i);
        const T &operator[](size_t i) const;
        size_t getSize() const;
        void selectionSort();
        static void selectionSort(T *a, size_t n);

        friend ostream &operator<<(ostream &os, const Array &a) {
            for (size_t i = 0; i < a.size; ++i) {
                os << a.data[i] << " ";
            }
            return os;
        }

        friend istream &operator>>(istream &is, Array &a) {
            for (size_t i = 0; i < a.size; ++i) {
                is >> a.data[i];
            }
            return is;
        }
    };

    template <class T> Array<T>::Array(size_t n) : size(n), data(n > 0 ? new T[n] : 0) {}

    template <class T> Array<T>::Array(const T *source, size_t n) : size(n), data(n > 0 ? new T[n] : 0) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = source[i];
        }
    }

    template <class T> Array<T>::Array(const Array &a) : size(a.size), data(a.size > 0 ? new T[a.size] : 0) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = a.data[i];
        }
    }

    template <class T> Array<T>::~Array() {
        delete[] data;
    }

    template <class T> Array<T> &Array<T>::operator=(const Array &a) {
        if (this != &a) {
            T *tmp = (a.size > 0) ? new T[a.size] : 0;
            for (size_t i = 0; i < a.size; ++i) {
                tmp[i] = a.data[i];
            }
            delete[] data;
            data = tmp;
            size = a.size;
        }
        return *this;
    }

    template <class T> T &Array<T>::operator[](size_t i) {
        return data[i];
    }

    template <class T> const T &Array<T>::operator[](size_t i) const {
        return data[i];
    }

    template <class T> size_t Array<T>::getSize() const {
        return size;
    }

    template <class T> void Array<T>::selectionSort() {
        selectionSort(data, size);
    }

    template <class T> void Array<T>::selectionSort(T *a, size_t n) {
        for (size_t i = 0; i + 1 < n; ++i) {
            size_t min = i;
            for (size_t j = i + 1; j < n; ++j) {
                if (a[j] < a[min]) {
                    min = j;
                }
            }
            if (min != i) {
                T tmp = a[i];
                a[i] = a[min];
                a[min] = tmp;
            }
        }
    }

}

int main() {
    setlocale(LC_ALL, "ukr");

    int n;
    cout << "Кількість елементів N=";
    cin >> n;
    if (!cin || n <= 0) {
        cerr << "Некоректне N" << endl;
        return 1;
    }
    MyLib::Array<int> a(n);
    cout << "Елементи масиву: ";
    cin >> a;
    if (!cin) {
        cerr << "Некоректне введення" << endl;
        return 1;
    }
    cout << "Початковий масив: " << a << endl;

    int *raw = new int[n];
    for (int i = 0; i < n; ++i) {
        raw[i] = a[i];
    }
    MyLib::Array<int>::selectionSort(raw, n);
    cout << "Статичний метод (звичайний масив): ";
    for (int i = 0; i < n; ++i) {
        cout << raw[i] << " ";
    }
    cout << endl;
    delete[] raw;

    a.selectionSort();
    cout << "Метод об'єкта: " << a << endl;

    double dv[] = {3.5, -1.2, 7.8, 0.0, 2.25};
    MyLib::Array<double> d(dv, 5);
    d.selectionSort();
    cout << "Масив double: " << d << endl;

    string sv[] = {"pear", "apple", "orange", "banana"};
    MyLib::Array<string> s(sv, 4);
    s.selectionSort();
    cout << "Масив string: " << s << endl;
    return 0;
}
