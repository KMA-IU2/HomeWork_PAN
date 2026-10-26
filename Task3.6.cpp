#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

class RocketStage {
private:
	double thrust;
	double burnTime;
	double mass;
public:
	RocketStage(double T, double B, double M)
		: thrust(T), burnTime(B), mass(M) {
	}

	double getDeltaV() { return thrust * burnTime / mass; }
	void printInfo() {
		cout << fixed << setprecision(2);
		cout << "Тяга: " << thrust << " Н, время: " << burnTime
			<< " с, масса: " << mass << " кг, ΔV = " << getDeltaV()
			<< " м/с" << endl;
	}
};


int main() {
	setlocale(0, "russian");
	RocketStage s1(5000, 10, 1000);
	RocketStage s2(7000, 8, 900);
	RocketStage s3(9000, 6, 800);

	s1.printInfo();
	s2.printInfo();
	s3.printInfo();

	double totalV = s1.getDeltaV() + s2.getDeltaV() + s3.getDeltaV();

	cout << fixed << setprecision(2);
	cout << "\nИтоговая скорость ракеты: " << totalV << " м/с" << endl;
	return 0;
}