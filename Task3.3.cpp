#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

class Engine {
private:
	double thrust;
	double fuelFlow;
public:
	//Конструктор
	Engine(double T, double F)
		: thrust(T), fuelFlow(F) {}

	double getSpecificimpulse() {return thrust / (fuelFlow * 9.81);}
	void printinfo() { 
		cout << "Тяга: " << thrust << " Н"
			<< " | Расход: " << fuelFlow << " кг/с"
			<< " | Удельный импульс: " << getSpecificimpulse() << " с" << endl;
	}
};

int main() {
	setlocale(0, "russian");
	Engine e1(5000, 2.5);
	e1.printinfo();
}