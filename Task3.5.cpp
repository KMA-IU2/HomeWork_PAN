#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

class Autopilot {
private:
	double courseAngle;
	double altitude;
public:
	Autopilot(double course, double alt)
		: courseAngle(course), altitude(alt) {
	}

	void changeCourse(double delta) { courseAngle += delta; }
	void changeAltitude(double delta) { altitude += delta; }
	void printStatus() {
		cout << fixed << setprecision(0);
		cout << " урс: " << courseAngle << "∞, высота: " 
			 << altitude << " м" << endl;
	}
};

int main() {
	setlocale(0, "russian");
	Autopilot a1(90, 1000);
	a1.changeCourse(10);
	a1.changeAltitude(500);
	a1.printStatus();
	return 0;
}