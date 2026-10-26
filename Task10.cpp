#include <locale.h>	
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    setlocale(0, "russian");
    const double g = 9.80665;

    double m, S, Cl, Cp, Ro, h;
    double Tmin, Tmax, dT;

    cout << "Введите массу самолёта m (кг): ";
    cin >> m;
    cout << "Введите площадь крыла S (м^2): ";
    cin >> S;
    cout << "Введите коэффициент подъёмной силы CL: ";
    cin >> Cl;
    cout << "Введите коэффициент сопротивления CD: ";
    cin >> Cp;
    cout << "Введите плотность воздуха rho (кг/м^3): ";
    cin >> Ro;
    cout << "Введите высоту набора h (м): ";
    cin >> h;
    cout << "Введите Tmin (Н): ";
    cin >> Tmin;
    cout << "Введите Tmax (Н): ";
    cin >> Tmax;
    cout << "Введите шаг dT (Н): ";
    cin >> dT;

    if (dT <= 0 || Tmax < Tmin || h <= 0 || m <= 0) {
        cout << "Ошибка в исходных данных!" << endl;
        return 1;
    }

    double bestT = 0.0, bestTime = 1e9;
    bool found = false;

    cout << fixed << setprecision(2);
    cout << "\n" << setw(10) << "T (Н)"
        << setw(14) << "V (м/с)"
        << setw(14) << "ay (м/с^2)"
        << setw(14) << "t (с)" << endl;
    cout << "--------------------------------------------------" << endl;

    for (double T = Tmin; T <= Tmax + 1e-9; T += dT) {
        double V = sqrt(2.0 * T / (Ro * S * Cp));

        double L = 0.5 * Ro * V * V * S * Cl;

        double ay = (L - m * g) / m;

        double t;
        if (ay > 0.0) {
            t = sqrt(2.0 * h / ay);
            if (!found || t < bestTime) {
                bestTime = t;
                bestT = T;
                found = true;
            }
        }
        else {
            t = -1.0;
        }

        cout << setw(10) << T
            << setw(14) << V
            << setw(14) << ay
            << setw(14) << (t < 0 ? -1.0 : t) << endl;
    }

    if (found) {
        cout << "\nОптимальная тяга: T = " << bestT
            << " Н, минимальное время набора высоты: t = "
            << bestTime << " с" << endl;
    }
    else {
        cout << "\nНи при одном значении тяги набор высоты невозможен." << endl;
    }

    return 0;
}