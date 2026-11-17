#include <iostream>
#include <queue>
#include <vector>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");

    int n;
    cout << "Кількість покупців N=";
    cin >> n;
    if (!cin || n <= 0) {
        cerr << "Некоректне N" << endl;
        return 1;
    }
    queue<double> service;
    for (int i = 1; i <= n; ++i) {
        double t;
        cout << "t" << i << "=";
        cin >> t;
        if (!cin || t <= 0) {
            cerr << "Час обслуговування має бути додатним числом" << endl;
            return 1;
        }
        service.push(t);
    }

    vector<double> stay;
    double finish = 0;
    double minService = service.front();
    int minService_i = 1;
    int i = 0;
    while (!service.empty()) {
        double t = service.front();
        service.pop();
        double arrival = i;
        double start = (finish > arrival) ? finish : arrival;
        finish = start + t;
        stay.push_back(finish - arrival);
        if (t < minService) {
            minService = t;
            minService_i = i + 1;
        }
        ++i;
    }

    int maxStay_i = 0;
    for (int k = 0; k < n; ++k) {
        cout << "c" << k + 1 << "=" << stay[k] << endl;
        if (stay[k] > stay[maxStay_i]) {
            maxStay_i = k;
        }
    }
    cout << "Найменше часу на обслуговування потрібно покупцю №" << minService_i << " (" << minService << " хв)" << endl;
    cout << "Найбільше часу в черзі провів покупець №" << maxStay_i + 1 << " (" << stay[maxStay_i] << " хв)" << endl;
    return 0;
}
