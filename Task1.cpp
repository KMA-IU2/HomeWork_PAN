#include <locale.h>	
#include <iostream>
using namespace std;

int main() {
	setlocale(0, "russian");
	double S;
	double V;
	double Ro;
	double Cl;
	cout << "Введите площадь крыла (м^2): ";
	cin >> S;
	cout << "Введите скорость полета (м/с): ";
	cin >> V;
	cout << "Введите плотность воздуха (кг/м^3): ";
	cin >> Ro;
	cout << "Введите коэффициент подъемной силы: ";
	cin >> Cl;
	double L = 0.5 * Ro * V * V * S * Cl;
	cout << "Подъемная сила = " << L << "Н";
	return 0;
}