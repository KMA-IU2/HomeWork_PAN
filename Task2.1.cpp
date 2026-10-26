#include <iostream>
#include <vector>
#include <iomanip>
#include <locale.h>	
using namespace std;

int main() {
    setlocale(0, "russian");
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    if (v0 <= 0) {
        cout << "Предупреждение: v0 должно быть > 0!" << endl;
        return 1;
    }

    vector<double> times, heights;
    times.reserve((int)(v0 * 2 / g / dt));

    for (double t = 0.0; t <= 1000.0; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0) break;
        times.push_back(t);
        heights.push_back(h);
    }

    cout << fixed << setprecision(2);
    cout << setw(10) << "t (c)" << setw(15) << "h (м)" << endl;
    cout << string(25, '-') << endl;
    for (size_t i = 0; i < times.size(); i++)
        cout << setw(10) << times[i] << setw(15) << heights[i] << endl;
    return 0;
}