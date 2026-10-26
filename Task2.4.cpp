#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <locale.h>	
using namespace std;

int main() {
    setlocale(0, "russian");
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 0.1;
    const double t_fall = 2.0 * v0 / g;

    vector<double> velocities;
    velocities.reserve((int)(t_fall / dt));

    for (double t = 0.0; t <= t_fall; t += dt) {
        double v = v0 - g * t;
        if (v < 0) break;
        velocities.push_back(v);
    }

    if (velocities.empty()) {
        cout << "Нет данных для расчёта!" << endl;
        return 1;
    }

    double sum = accumulate(velocities.begin(), velocities.end(), 0.0);
    double avg = sum / velocities.size();

    cout << fixed << setprecision(3);
    cout << "Количество шагов: " << velocities.size() << endl;
    cout << "Сумма скоростей: " << sum << " м/с" << endl;
    cout << "Средняя скорость (по точкам): " << avg << " м/с" << endl;

    double integral = v0 * t_fall - 0.5 * g * t_fall * t_fall;
    double avg_integral = integral / t_fall;
    cout << "Интегральное среднее: " << avg_integral << " м/с" << endl;

    return 0;
}