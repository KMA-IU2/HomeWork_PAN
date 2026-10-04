#include <locale.h>	
#include <iostream>
using namespace std;

int main() {
	setlocale(0, "russian");
	double ay;
	double h;
	cout << "Введите вертикальное ускорение (м/с^2): ";
	cin >> ay;
	cout << "Введите высоту (м): ";
	cin >> h;
	double t = sqrt(2 * h / ay);
	if (ay > 0 and h > 0) {
		cout << "Время необходимое для набора " << h << "м = " << t << endl;
	}
	else {
		cout << "Данные введены не верно!" << endl;
	}
	return 0;
}