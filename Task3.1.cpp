#include <iostream>
#include <iomanip>
#include <locale.h>
using namespace std;

class Sensor {
private:
	double signalStrength;
	bool isActive;

public:
	//Конструктор
	Sensor(double Strength) : signalStrength(Strength), isActive(true) {}

	void activate() { isActive = true; }
	void deactivate() { isActive = false; }

	void setSignalStrength(double s) {
		if (s < 0) s = 0;
		signalStrength = s;
	}

	double getSignalStrength() { return signalStrength; }

	void printStatus() {
		cout << fixed << setprecision(1);
		cout << (isActive ? "Датчик активен" : "Датчик выключен")
			<< " | Сила сигнала: " << signalStrength << " дБ" << endl;
	}
};

int main() {
	setlocale(0, "russian");
	Sensor s1(45.5);
	s1.printStatus();
	s1.setSignalStrength(-10);
	s1.printStatus();
	s1.deactivate();
	s1.printStatus();
	return 0;
}