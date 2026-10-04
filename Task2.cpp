#include <locale.h>	
#include <iostream>
using namespace std;

double airresistane(double s, double v, double ro, double cp) {
	double l = 0.5 * ro * v * v * s * cp;
	return l;
}

int main() {
	setlocale(0, "russian");
	double S;
	double V;
	double Ro;
	double Cp;
	cout << "Введите площадь крыла (м^2): ";
	cin >> S;
	cout << "Введите скорость полета (м/с): ";
	cin >> V;
	cout << "Введите плотность воздуха (кг/м^3): ";
	cin >> Ro;
	cout << "Введите коэффициент опротивления: ";
	cin >> Cp;
	double L = airresistane(S, V, Ro, Cp);
	cout << "Аэродинамическое сопротивление = " << L << "Н";
		return 0;
}