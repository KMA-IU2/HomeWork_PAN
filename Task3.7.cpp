#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

class FlightComputer {
private:
    double altitude;
    double velocity;
    double fuel;
    double thrust;

public:
    FlightComputer(double alt, double vel, double f, double T)
        : altitude(alt), velocity(vel), fuel(f), thrust(T) {
    }
    
    void simulateStep(double dt) {
        velocity += ((thrust / 1000) - 9.8) * 2 * dt;
        altitude += velocity * dt;
        fuel -= dt * 2;
    }

    void printStatus(double t) const {
        cout << fixed << setprecision(2);
        cout << "t=" << t << "c: высота=" << altitude << "м, скорость="
            << velocity << "м/с, топливо=" << fuel << endl;
    }
};

int main() {
    setlocale(0, "russian");
    FlightComputer fc(0, 0, 100, 12000);
    for (int i = 0; i < 5; i++) {
        double t = (i + 1) * 0.5;
        fc.simulateStep(0.5);
        fc.printStatus(t);
    }
    return 0;
}