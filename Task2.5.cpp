#include <iostream>
#include <vector>
#include <iomanip>
#include <locale.h>	
using namespace std;

struct Point {
    double x, y, z;
};

int main() {
    setlocale(0, "russian");
    const double vx = 30.0;
    const double vy = 20.0;
    const double vz = 40.0;
    const double dt = 0.5;
    const double t_max = 5.0;

    vector<Point> traj;
    traj.reserve((int)(t_max / dt));

    double x = 0.0, y = 0.0, z = 0.0;

    traj.push_back({ x, y, z });

    for (double t = 0; t <= t_max; t += dt) {
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
        traj.push_back({ x, y, z });
    }

    cout << fixed << setprecision(2);
    cout << setw(8) << "t (с)"
        << setw(12) << "x (м)"
        << setw(12) << "y (м)"
        << setw(12) << "z (м)" << endl;
    cout << string(44, '-') << endl;

    for (size_t i = 0; i < traj.size(); i++) {
        double t = i * dt;
        cout << setw(8) << t
            << setw(12) << traj[i].x
            << setw(12) << traj[i].y
            << setw(12) << traj[i].z << endl;
    }

    double t_last = (traj.size() - 1) * dt;
    cout << "\nПроверка: x = vx*t = " << vx * t_last
        << " м, traj.back().x = " << traj.back().x << " м" << endl;

    return 0;
}