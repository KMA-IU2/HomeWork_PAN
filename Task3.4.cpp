#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

class Gyroscope {
private:
	double angularVelocity;
	bool calibrationRequired;
public:
	Gyroscope(double ang, bool cal)
		: angularVelocity(ang), calibrationRequired(cal) {}
	
	void calibrate() {calibrationRequired = false;}

	void printStatus() {
		cout << fixed << setprecision(1);
		cout << "Скорость: " << angularVelocity << " °/с"
			<< " | Калибровка " << (calibrationRequired ? "требуется" : "не требуется") << endl;
	}
};

int main() {
	setlocale(0, "russian");
	Gyroscope g1(120.5, true);
	g1.printStatus();
	g1.calibrate();
	g1.printStatus();
	return 0;
}