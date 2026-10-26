#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <locale.h>
using namespace std;

int main() {
    setlocale(0, "russian");
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 0.1;

    vector<double> times, heights;
    times.reserve((int)(v0 * 2 / g / dt) + 1);
    heights.reserve((int)(v0 * 2 / g / dt) + 1);

    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        times.push_back(t);
        heights.push_back(h);
        if (t > 0 && h <= 0.0) break;
    }

    if (heights.empty()) {
        cout << "Нет данных!" << endl;
        return 1;
    }

    auto it = max_element(heights.begin(), heights.end());
    size_t idx = distance(heights.begin(), it);

    cout << fixed << setprecision(2);
    cout << "Максимальная высота: " << *it << " м" << endl;
    cout << "Достигнута в момент t = " << times[idx] << " с" << endl;

    cout << "\nПроверка:" << endl;
    cout << "  h_max = v0^2/(2g) = " << v0 * v0 / (2 * g) << " м" << endl;
    cout << "  t_max = v0/g      = " << v0 / g << " с" << endl;

    return 0;
}