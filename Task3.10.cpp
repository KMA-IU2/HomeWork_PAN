#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class DroneFlight {
private:
    vector<double> x, y;
    double totalDistance;
public:
    DroneFlight() : totalDistance(0) {
        x.push_back(0);
        y.push_back(0);
    }

    void addPoint(double newX, double newY) {
        double dx = newX - x.back();
        double dy = newY - y.back();
        totalDistance += sqrt(dx * dx + dy * dy);
        x.push_back(newX);
        y.push_back(newY);
    }

    double getTotalDistance() { return totalDistance; }

    void printPath() const {
        cout << "Точки маршрута:" << endl;
        for (size_t i = 0; i < x.size(); ++i)
            cout << "(" << x[i] << ", " << y[i] << ")" << endl;
    }
};

int main() {
    setlocale(0, "russian");
    DroneFlight d;
    d.addPoint(0, 0);
    d.addPoint(3, 4);
    d.addPoint(6, 8);
    d.printPath();
    cout << fixed << setprecision(0);
    cout << "Пройдено: " << d.getTotalDistance() << " м" << endl;
    return 0;
}