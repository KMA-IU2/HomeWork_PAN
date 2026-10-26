#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <locale.h>
using namespace std;

int main() {
    setlocale(0, "russian");
    vector<double> heights = { 5.0, 15.0, 8.0, 25.0, 3.0, 40.0, 2.0, 30.0, 12.0 };

    cout << fixed << setprecision(1);
    cout << "Исходные высоты (" << heights.size() << " шт.): ";
    for (double h : heights) cout << h << " ";
    cout << endl;

    auto new_end = remove_if(heights.begin(), heights.end(),
        [](double h) { return h < 10.0; });
    heights.erase(new_end, heights.end());

    cout << "После удаления (" << heights.size() << " шт.): ";
    for (double h : heights) cout << h << " ";
    cout << endl;

    return 0;
}