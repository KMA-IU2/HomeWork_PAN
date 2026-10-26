#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <locale.h>
using namespace std;

int main() {
    setlocale(0, "russian");
    vector<double> sensor = {
        0.0, 0.12, 0.0, 0.35, 0.0, 0.0, 0.08, 0.0,
        0.21, 0.0, 0.0, 0.15, 0.0, 0.42, 0.0, 0.0
    };

    int zeros = count(sensor.begin(), sensor.end(), 0.0);

    cout << fixed << setprecision(2);
    cout << "Всего измерений: " << sensor.size() << endl;
    cout << "Нулевых показаний: " << zeros << endl;

    if (sensor.empty()) {
        cout << "Вектор пуст!" << endl;
    }
    else {
        double percent = 100.0 * zeros / sensor.size();
        cout << "Доля нулевых: " << percent << " %" << endl;
    }

    return 0;
}