#include <iostream>
#include <vector>
#include <iomanip>
#include <locale.h>
using namespace std;

// ---------- Точка ----------
struct Point {
    double x, y, z;
};

// ---------- Класс ракеты ----------
class Rocket {
public:
    double mass;
    double vx, vy, vz;
    double x, y, z;

    vector<Point> trajectory;

    Rocket(double m, double vx_, double vy_, double vz_,
        double x0 = 0, double y0 = 0, double z0 = 0)
        : mass(m), vx(vx_), vy(vy_), vz(vz_),
        x(x0), y(y0), z(z0) {
    }

    void updatePosition(double dt) {
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
        trajectory.push_back({ x, y, z });
    }

    void changeVelocity(double dvx, double dvy, double dvz) {
        vx += dvx;
        vy += dvy;
        vz += dvz;
    }

    Point getPosition() const {
        return { x, y, z };
    }

    Point getVelocity() const {
        return { vx, vy, vz };
    }
};

int main() {
    setlocale(0, "russian");
    const double dt = 0.1;
    const double T = 10.0;

    vector<Rocket> squad;
    squad.reserve(5);

    squad.emplace_back(1000, 10, 0, 50);
    squad.emplace_back(900, 15, -5, 40);
    squad.emplace_back(1100, 20, 5, 60);
    squad.emplace_back(950, 12, 3, 45);
    squad.emplace_back(1050, 18, -2, 55);

    for (auto& r : squad)
        r.trajectory.reserve((int)(T / dt));

    for (double t = 0.0; t <= T; t += dt) {
        for (auto& r : squad)
            r.updatePosition(dt);
    }

    // ---------- Вывод конечных положений ----------
    cout << fixed << setprecision(2);
    cout << setw(10) << "Ракета"
        << setw(12) << "x (м)"
        << setw(12) << "y (м)"
        << setw(12) << "z (м)"
        << setw(16) << "точек в траектории" << endl;
    cout << string(62, '-') << endl;

    for (size_t i = 0; i < squad.size(); ++i) {
        Point p = squad[i].getPosition();
        cout << setw(10) << i + 1
            << setw(12) << p.x
            << setw(12) << p.y
            << setw(12) << p.z
            << setw(16) << squad[i].trajectory.size() << endl;
    }

    return 0;
}