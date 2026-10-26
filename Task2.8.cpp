#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <locale.h>
using namespace std;

int main() {
    setlocale(0, "russian");
    const double g = 9.8;
    const double dt = 0.1;
    const double t_max = 100.0;

    // --- Ракета 1: v0 = 50 ---
    vector<double> times1, heights1;
    for (double t = 0.0; t <= t_max; t += dt) {
        double h = 50.0 * t - 0.5 * g * t * t;
        times1.push_back(t);
        heights1.push_back(h);
        if (t > 0 && h <= 0.0) break;
    }

    // --- Ракета 2: v0 = 70 ---
    vector<double> times2, heights2;
    for (double t = 0.0; t <= t_max; t += dt) {
        double h = 70.0 * t - 0.5 * g * t * t;
        times2.push_back(t);
        heights2.push_back(h);
        if (t > 0 && h <= 0.0) break;
    }

    if (heights1.empty() || heights2.empty()) {
        cout << "Нет данных!" << endl;
        return 1;
    }

    // --- Ракета 1: максимум ---
    auto it_max1 = max_element(heights1.begin(), heights1.end());
    size_t idx_max1 = distance(heights1.begin(), it_max1);
    double max1 = *it_max1;
    double t_max1 = times1[idx_max1];

    // --- Ракета 1: падение ---
    auto it_fall1 = find_if(heights1.begin() + 1, heights1.end(),
        [](double h) { return h <= 0.0; });
    bool fell1 = (it_fall1 != heights1.end());
    double t_fall1 = fell1 ? times1[distance(heights1.begin(), it_fall1)]
        : times1.back();

    // --- Ракета 2: максимум ---
    auto it_max2 = max_element(heights2.begin(), heights2.end());
    size_t idx_max2 = distance(heights2.begin(), it_max2);
    double max2 = *it_max2;
    double t_max2 = times2[idx_max2];

    // --- Ракета 2: падение ---
    auto it_fall2 = find_if(heights2.begin() + 1, heights2.end(),
        [](double h) { return h <= 0.0; });
    bool fell2 = (it_fall2 != heights2.end());
    double t_fall2 = fell2 ? times2[distance(heights2.begin(), it_fall2)]
        : times2.back();

    // --- Таблица сравнения ---
    cout << fixed << setprecision(2);
    cout << setw(22) << "Параметр"
        << setw(18) << "Ракета 1"
        << setw(18) << "Ракета 2" << endl;
    cout << string(58, '-') << endl;
    cout << setw(22) << "Макс. высота (м)"
        << setw(18) << max1
        << setw(18) << max2 << endl;
    cout << setw(22) << "Время макс. (с)"
        << setw(18) << t_max1
        << setw(18) << t_max2 << endl;
    cout << setw(22) << "Время падения (с)"
        << setw(18) << t_fall1
        << setw(18) << t_fall2 << endl;
    cout << setw(22) << "Упала?"
        << setw(18) << (fell1 ? "да" : "нет")
        << setw(18) << (fell2 ? "да" : "нет") << endl;
    cout << string(58, '-') << endl;

    // --- Выводы ---
    if (max1 > max2)
        cout << "\nВыше поднялась: ракета 1 (" << max1 << " м)" << endl;
    else
        cout << "\nВыше поднялась: ракета 2 (" << max2 << " м)" << endl;

    if (fell1 && fell2) {
        if (t_fall1 > t_fall2)
            cout << "Дольше в воздухе: ракета 1 (" << t_fall1 << " с)" << endl;
        else
            cout << "Дольше в воздухе: ракета 2 (" << t_fall2 << " с)" << endl;
    }
    else if (!fell1 && !fell2) {
        cout << "Обе ракеты ещё в воздухе на момент t = " << t_max << " с" << endl;
    }
    else if (!fell1) {
        cout << "Дольше в воздухе: ракета 1 (ещё не упала)" << endl;
    }
    else {
        cout << "Дольше в воздухе: ракета 2 (ещё не упала)" << endl;
    }

    return 0;
}