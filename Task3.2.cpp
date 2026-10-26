#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;


class Trajectory {
private:
	double startX, startY;
	double angle;

public:
	//Конструктор по умолчанию
	Trajectory() : startX(0), startY(0), angle(0) {}


	//Конструктор параметрический
	Trajectory(double x, double y, double ang)
		: startX(x), startY(y), angle(ang) {
	}

	void printTrajectory() {
		cout << fixed << setprecision(1);
		cout << "Старт: (" << startX << ", "
			<< startY << "), угол: "
			<< angle << "°" << endl;
	}
};

int main() {
	setlocale(0, "russian");
	Trajectory t1;
	Trajectory t2(100, 200, 45);
	t1.printTrajectory();
	t2.printTrajectory();
}