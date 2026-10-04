#include <locale.h>	
#include <iostream>
using namespace std;

struct Aircraft {
    double T;
    double L;
    double D;
    double ay;
    double m;
};

double g = 9.80665;


int main() {
    setlocale(0, "russian");
    Aircraft Air;

    Air.m = 5000;
    cout << "Введите тягу: ";
    cin >> Air.T;
    cout << "Введите подъемную силу: ";
    cin >> Air.L;
    cout << "Введите силу сопротивления: ";
    cin >> Air.D;

    Air.ay = (Air.L - Air.m * g) / Air.m;

    if (Air.ay > 0.5) {
        cout << "Набор высоты" << endl;
    }
    else if (Air.ay < 0) {
        cout << "Снижение" << endl;
    }
    else {
        cout << "Горизонтальный полет" << endl;
    }

	return 0;
}