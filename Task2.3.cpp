#include <iostream>
#include <vector>
#include <iomanip>
#include <locale.h>	
using namespace std;

int main() {
    setlocale(0, "russian");
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 0.5;
    const double t_max = 1000.0;

    if (v0 <= 0 || dt <= 0) {
        cout << "Ошибка: v0 и dt должны быть положительными!" << endl;
        return 1;
    }

    vector<double> times, velocities;
    times.reserve((int)(t_max / dt));
    velocities.reserve((int)(t_max / dt));

    for (double t = 0.0; t <= t_max; t += dt) {
        double v = v0 - g * t;
        if (v < 0) break;
        times.push_back(t);
        velocities.push_back(v);
    }

    cout << fixed << setprecision(2);
    cout << setw(10) << "t (c)" << setw(15) << "v (м/с)" << endl;
    cout << string(25, '-') << endl;
    for (size_t i = 0; i < times.size(); i++) {
        cout << setw(10) << times[i]
            << setw(15) << velocities[i] << endl;
    }

    cout << "\nМомент смены знака скорости: t = v0/g = "
        << v0 / g << " с" << endl;

    return 0;
}