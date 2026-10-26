#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <locale.h>
using namespace std;

int main() {
    setlocale(0, "russian");
    vector<double> y = { 0.0, 10.0, 25.0, 45.0, 40.0, 60.0, 55.0, 30.0 };

    vector<double> diffs(y.size());

    adjacent_difference(y.begin(), y.end(), diffs.begin());

    cout << fixed << setprecision(2);
    cout << setw(6) << "i"
        << setw(12) << "y[i]"
        << setw(14) << "diff[i]" << endl;
    cout << string(32, '-') << endl;
    for (size_t i = 0; i < y.size(); ++i) {
        cout << setw(6) << i
            << setw(12) << y[i]
            << setw(14) << diffs[i] << endl;
    }

    double total_path = 0.0;
    for (size_t i = 1; i < diffs.size(); ++i)
        total_path += fabs(diffs[i]);

    double total_path2 = accumulate(
        diffs.begin() + 1, diffs.end(), 0.0,
        [](double acc, double d) { return acc + fabs(d); }
    );

    double net_displacement = y.back() - y.front();

    cout << "\nСуммарный путь (по модулю): " << total_path << " м" << endl;
    cout << "Проверка через accumulate:  " << total_path2 << " м" << endl;
    cout << "Чистое перемещение (y_end - y_start): " << net_displacement << " м" << endl;

    return 0;
}