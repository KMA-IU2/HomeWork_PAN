#include <iostream>
#include <vector>
#include <algorithm>
#include <locale.h>
using namespace std;

int main() {
    setlocale(0, "russian");
    vector<double> x = { 5.0, 2.0, 8.0, 2.0, 5.0, 1.0, 8.0, 3.0, 5.0, 1.0, 2.0 };

    cout << "Исходные данные (" << x.size() << " шт.):\n";
    for (double x : x) cout << x << " ";
    cout << "\n\n";

    sort(x.begin(), x.end());

    cout << "После сортировки (" << x.size() << " шт.):\n";
    for (double x : x) cout << x << " ";
    cout << "\n\n";

    x.erase(unique(x.begin(), x.end()), x.end());

    cout << "Уникальные координаты (" << x.size() << " шт.):\n";
    for (double x : x) cout << x << " ";
    cout << endl;

    return 0;
}