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

    for (double t = 1.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        times.push_back(t);
        heights.push_back(h);
        if (t > 0 && h <= 0.0) break;
    }

    auto it = find_if(heights.begin(), heights.end(),
        [](double h) { return h <= 0.0; });

    cout << fixed << setprecision(2);
    if (it == heights.end()) {
        cout << "Падения не было в диапазоне." << endl;
    }
    else {
        size_t idx = distance(heights.begin(), it);
        double t_fall = times[idx];
        cout << "Момент падения: t = " << t_fall
            << " с, h = " << heights[idx] << " м" << endl;

        cout << "Проверка: idx * dt = " << idx * dt << " с" << endl;
    }

    return 0;
}