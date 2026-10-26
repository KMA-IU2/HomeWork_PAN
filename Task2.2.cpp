#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <locale.h>	
using namespace std;

int main() {
    setlocale(0, "russian");
    const double v0 = 50.0, g = 9.8, dt = 0.1;
    vector<double> times, heights;
    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0) break;
        times.push_back(t);
        heights.push_back(h);
    }

    if (heights.empty()) {
        cout << "Данных нет!" << endl;
        return 1;
    }

    // Вариант 1: вручную
    size_t idx_max = 0;
    for (size_t i = 1; i < heights.size(); i++)
        if (heights[i] > heights[idx_max]) idx_max = i;

    // Вариант 2: через STL
    auto it = max_element(heights.begin(), heights.end());
    size_t idx_stl = distance(heights.begin(), it);

    cout << fixed << setprecision(2);
    cout << "Максимальная высота: " << heights[idx_max]
        << " м в момент t = " << times[idx_max] << " с" << endl;
    cout << "STL-проверка: " << *it << " в t = " << times[idx_stl] << " с" << endl;
    return 0;
}