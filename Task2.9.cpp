#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <locale.h>
using namespace std;

int main() {
    setlocale(0, "russian");
    vector<double> h = {
        0.0, 12.5, 24.0, 31.5, 28.0, 36.5, 40.0, 37.5, 20.0, 5.0
    };

    size_t n = h.size();
    if (n == 0) {
        cout << "Вектор пуст!" << endl;
        return 1;
    }

    vector<double> smoothed(n);

    smoothed[0] = h[0];
    if (n > 1) smoothed[n - 1] = h[n - 1];

    for (size_t i = 1; i + 1 < n; ++i) {
        smoothed[i] = (h[i - 1] + h[i] + h[i + 1]) / 3.0;
    }

    // --- Вывод в две колонки ---
    cout << fixed << setprecision(2);
    cout << setw(6) << "i"
        << setw(12) << "h[i]"
        << setw(15) << "smoothed[i]" << endl;
    cout << string(33, '-') << endl;

    for (size_t i = 0; i < n; ++i) {
        cout << setw(6) << i
            << setw(12) << h[i]
            << setw(15) << smoothed[i] << endl;
    }

    return 0;
}