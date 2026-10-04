#include <locale.h>	
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Aircraft {
    int num;
    double m; 
    double T;
    double Cl;
    double Cp;
    double ay;
    double t;
    double L;
};

double g = 9.80665;

int main() {
	setlocale(0, "russian");
    double h;
    int size;
    cout << "Введите заданную высоту: " << endl;
    cin >> h;
    cout << "Введите количество самолетов: " << endl;
    cin >> size;

    Aircraft *Air = new Aircraft[size];

    for (int i = 0; i < size; i++) {
        Air[i].num = i+1;

        cout << "Самолет номер " << i+1 << ":\n";
        cout << "Введите тягу T: ";
        cin >> Air[i].T;
        cout << "Введите коэффициент подъёмной силы Cl: ";
        cin >> Air[i].Cl;
        cout << "Введите коэффициент сопротивления Cp: ";
        cin >> Air[i].Cp;
        cout << "Введите массу m: ";
        cin >> Air[i].m;
        cout << "Введите подъёмную силу L: ";
        cin >> Air[i].L;

        if (Air[i].m <= 0) {
            cout << "Масса должна быть положительной. Пропускаем этот самолёт.\n";
            Air[i].ay = 0.0;
            Air[i].t = 0.0;
            continue;
        }

        Air[i].ay = (Air[i].L - Air[i].m * g) / Air[i].m;

        double underSqrt = 2.0 * h / Air[i].ay;
        if (underSqrt < 0 || Air[i].ay == 0) {
            Air[i].t = 1e300;
        }
        else {
            Air[i].t = sqrt(underSqrt);
        }
    }

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (Air[j].t > Air[j + 1].t) {
                Aircraft tmp = Air[j];
                Air[j] = Air[j + 1];
                Air[j + 1] = tmp;
            }
        }
    }

    cout << left
        << setw(5) << "num"
        << setw(10) << "m"
        << setw(12) << "T"
        << setw(8) << "Cl"
        << setw(8) << "Cp"
        << setw(15) << "ay"
        << setw(15) << "t"
        << setw(10) << "L" << "\n";
    cout << string(77, '-') << "\n";

    for (int i = 0; i < size; ++i) {
        cout << left
            << setw(5) << Air[i].num
            << setw(10) << Air[i].m
            << setw(12) << Air[i].T
            << setw(8) << Air[i].Cl
            << setw(8) << Air[i].Cp
            << setw(15) << Air[i].ay
            << setw(15) << Air[i].t
            << setw(10) << Air[i].L << "\n";
    }

    delete[] Air;
    return 0;
}