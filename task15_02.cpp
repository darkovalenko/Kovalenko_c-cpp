#include <iostream>
#include <vector>
#include <cmath>
#include <clocale>

using namespace std;

class Point {
    double x;
    double y;
    static int count;

public:
    Point() : x(0), y(0) {
        count++;
    }

    Point(double x_, double y_) : x(x_), y(y_) {
        count++;
    }

    Point(const Point &p) : x(p.x), y(p.y) {
        count++;
    }

    ~Point() {
        count--;
    }

    Point &operator=(const Point &p) {
        x = p.x;
        y = p.y;
        return *this;
    }

    static int counter() {
        return count;
    }

    double distance(const Point &p) const {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }

    friend ostream &operator<<(ostream &os, const Point &p) {
        os << "(" << p.x << "; " << p.y << ")";
        return os;
    }

    friend istream &operator>>(istream &is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }
};

int Point::count = 0;

double perimeter(const vector<Point> &v) {
    double p = 0;
    for (size_t i = 0; i < v.size(); i++) {
        p += v[i].distance(v[(i + 1) % v.size()]);
    }
    return p;
}

int main() {
    setlocale(LC_ALL, "ukr");
    vector<Point> polygon;
    int answer;
    while (true) {
        cout << "Ввести вершину? (1 - так, 0 - ні): ";
        cin >> answer;
        if (!cin || answer == 0) {
            break;
        }
        Point p;
        cout << "x y = ";
        cin >> p;
        if (!cin) {
            cerr << "Некоректне введення" << endl;
            return 1;
        }
        polygon.push_back(p);
    }
    cout << "Кількість вершин: " << Point::counter() << endl;
    if (polygon.size() < 3) {
        cout << "Для багатокутника потрібно щонайменше 3 вершини" << endl;
        return 0;
    }
    for (size_t i = 0; i < polygon.size(); i++) {
        cout << i + 1 << ": " << polygon[i] << endl;
    }
    cout << "Периметр: " << perimeter(polygon) << endl;
    return 0;
}
