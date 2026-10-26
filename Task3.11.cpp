#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

class Engine {
private:
    double thrust;
    double fuelFlow;
    double fuel;

public:
    Engine(double T, double F, double f)
        : thrust(T), fuelFlow(F), fuel(f) {
    }

    double getThrust() { return thrust; }
    bool hasFuel() { return fuel > 0; }
    void burn(double dt) {
        if (hasFuel()) {
            fuel -= fuelFlow * dt;
            if (fuel < 0) fuel = 0;
        }
    }

    double getFuel() { return fuel; }
};

class Navigation {
private:
    double altitude;
    double velocity;
    double acceleration;
    double mass;    
public:
    Navigation(double alt, double v, double m)
        : altitude(alt), velocity(v), mass(m) {}
    void update(double thrust, double dt) {
        acceleration = thrust / mass - 9.81;
        velocity += acceleration * dt;
        altitude += velocity * dt;
    }

    void printStatus(double time) const {
        cout << fixed << setprecision(2);
        cout << "t=" << time << "c | h=" << altitude << "м | v="
            << velocity << "м/с | a=" << acceleration << "м/с^2" << endl;
    }
};

class AutonomousFlightSystem {
private:
    Engine engine;
    Navigation nav;
    double time;
public:
    AutonomousFlightSystem(const Engine& e, const Navigation& n)
        : engine(e), nav(n), time(0.0) {
    }

    void simulate(double dt, double totalTime) {
        while (time < totalTime && engine.hasFuel()) {
            engine.burn(dt);
            nav.update(engine.getThrust(), dt);
            nav.printStatus(time);
            time += dt;
        }
    }

    void printSummary() {
        cout << "--- Полет завершен ---" << endl;
        cout << "Оставшееся топливо: " << engine.getFuel() << " кг" << endl;
    }
};

int main() {
    setlocale(0, "russian");
    Engine engine(5000, 2.5, 10);
    Navigation nav(0, 0, 500);
    AutonomousFlightSystem afs(engine, nav);

    afs.simulate(1.0, 10.0);
    afs.printSummary();
    return 0;
}