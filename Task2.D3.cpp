#include <iostream>
#include <vector>
#include <algorithm>
#include <locale.h>
using namespace std;

int main() {
    setlocale(0, "russian");
    vector<double> temps = {
        50.0, 70.0, -150.0, 80.0, 250.0, 60.0, -200.0, 90.0, 120.0, 300.0, 45.0
    };

    cout << "Исходные данные (" << temps.size() << " шт.):\n";
    for (double t : temps) cout << t << " ";
    cout << "\n\n";

    temps.erase(
        remove_if(temps.begin(), temps.end(),
            [](double x) { return x < -100.0 || x > 200.0; }),
        temps.end()
    );

    cout << "После очистки (" << temps.size() << " шт.):\n";
    for (double t : temps) cout << t << " ";
    cout << endl;

    return 0;
}