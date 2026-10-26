#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

class NavigationSystem {
private:
    double x, y;
    double velocityX, velocityY;
    bool gpsAvailable;

public:
    NavigationSystem(double x0, double y0, double vx, double vy, bool gps)
        : x(x0), y(y0), velocityX(vx), velocityY(vy), gpsAvailable(gps) {
    }
    void integratePosition(double dt) {
        x += velocityX * dt;
        y += velocityY * dt;
    }

    void correctGPS(double realX, double realY) {
        if (gpsAvailable) {
            x = (realX + x) / 2;
            y = (realY + y) / 2;
        }
    }

    void printPosition() const {
        cout << fixed << setprecision(1);
        cout << "Координаты: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    setlocale(0, "russian");
    NavigationSystem nav(0, 0, 100, 50, true);
    nav.integratePosition(1);
    nav.correctGPS(110, 60);
    nav.printPosition();
    return 0;
}