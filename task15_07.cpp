#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

class Triangle {
    double left;
    double right;
    double apex;

    static double pi() {
        return acos(-1.0);
    }

    static double radToDeg(double r) {
        return r * 180 / pi();
    }

public:
    Triangle();
    Triangle(double leftSide, double rightSide, double apexDegrees);
    bool set(double leftSide, double rightSide, double apexDegrees);
    bool input();
    void print() const;
    double leftSide() const;
    double rightSide() const;
    double base() const;
    double apexAngle() const;
    double leftAngle() const;
    double rightAngle() const;
    double area() const;
    double perimeter() const;
};

Triangle::Triangle() : left(1), right(1), apex(pi() / 3) {}

Triangle::Triangle(double leftSide, double rightSide, double apexDegrees) : left(1), right(1), apex(pi() / 3) {
    if (!set(leftSide, rightSide, apexDegrees)) {
        cerr << "Некоректні дані, створено трикутник за замовчуванням" << endl;
    }
}

bool Triangle::set(double leftSide, double rightSide, double apexDegrees) {
    if (leftSide <= 0 || rightSide <= 0 || apexDegrees <= 0 || apexDegrees >= 180) {
        return false;
    }
    left = leftSide;
    right = rightSide;
    apex = apexDegrees * pi() / 180;
    return true;
}

bool Triangle::input() {
    double l, r, a;
    cout << "Ліва бічна сторона: ";
    cin >> l;
    cout << "Права бічна сторона: ";
    cin >> r;
    cout << "Верхній кут (градуси): ";
    cin >> a;
    if (!cin) {
        return false;
    }
    if (!set(l, r, a)) {
        cout << "Сторони мають бути додатними, а кут у межах (0; 180)" << endl;
        return false;
    }
    return true;
}

void Triangle::print() const {
    cout << "Бічні сторони: " << left << " і " << right << ", верхній кут: " << radToDeg(apex) << " градусів" << endl;
}

double Triangle::leftSide() const {
    return left;
}

double Triangle::rightSide() const {
    return right;
}

double Triangle::base() const {
    return sqrt(left * left + right * right - 2 * left * right * cos(apex));
}

double Triangle::apexAngle() const {
    return radToDeg(apex);
}

double Triangle::leftAngle() const {
    double c = base();
    return radToDeg(acos((left * left + c * c - right * right) / (2 * left * c)));
}

double Triangle::rightAngle() const {
    return 180 - apexAngle() - leftAngle();
}

double Triangle::area() const {
    return left * right * sin(apex) / 2;
}

double Triangle::perimeter() const {
    return left + right + base();
}

int main() {
    setlocale(LC_ALL, "ukr");
    Triangle t;
    if (!t.input()) {
        cerr << "Некоректне введення" << endl;
        return 1;
    }
    t.print();
    cout << "Довжини сторін: " << t.leftSide() << ", " << t.rightSide() << ", основа " << t.base() << endl;
    cout << "Кути: " << t.leftAngle() << ", " << t.rightAngle() << ", " << t.apexAngle() << endl;
    cout << "Площа: " << t.area() << endl;
    cout << "Периметр: " << t.perimeter() << endl;
    return 0;
}
