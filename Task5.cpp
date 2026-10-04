#include <locale.h>	
#include <iostream>
using namespace std;

struct Aircraft {
    double m;
    double S;
    double T;
    double Cp;
    double Cl;
    double t;
    double V;
    double L;
    double D;
    double ay;
    double a;

};
double Ro = 1.225;
double g = 9.80665;


int main(){
	setlocale(0, "russian");
    
    Aircraft Air1;
    Aircraft Air2;
    Aircraft Air3;
 
    cout << "Введите массу 1-го самолета (кг): ";
    cin >> Air1.m;
    cout << "Введите площадь крыла 1-го самолета (м^2): ";
    cin >> Air1.S;
    cout << "Введите тягу 1-го самолета (Н): ";
    cin >> Air1.T;
    cout << "Ввдите скорость полета 1-го самолета (м/с): ";
    cin >> Air1.V;
    cout << "Введите коэффициент сопротивления 1-го самолета (Н): ";
    cin >> Air1.Cp;
    cout << "Введите коэффициент подъемной силы 1-го самолета (Н): ";
    cin >> Air1.Cl;

    cout << "Введите массу 2-го самолета (кг): ";
    cin >> Air2.m;
    cout << "Введите площадь крыла 2-го самолета (м^2): ";
    cin >> Air2.S;
    cout << "Введите тягу 2-го самолета (Н): ";
    cin >> Air2.T;
    cout << "Ввдите скорость полета 2-го самолета (м/с): ";
    cin >> Air2.V;
    cout << "Введите коэффициент сопротивления 2-го самолета (Н): ";
    cin >> Air2.Cp;
    cout << "Введите коэффициент подъемной силы 2-го самолета (Н): ";
    cin >> Air2.Cl;

    cout << "Введите массу 3-го самолета (кг): ";
    cin >> Air3.m;
    cout << "Введите площадь крыла 3-го самолета (м^2): ";
    cin >> Air3.S;
    cout << "Введите тягу 3-го самолета (Н): ";
    cin >> Air3.T;
    cout << "Ввдите скорость полета 3-го самолета (м/с): ";
    cin >> Air3.V;
    cout << "Введите коэффициент сопротивления 3-го самолета (Н): ";
    cin >> Air3.Cp;
    cout << "Введите коэффициент подъемной силы 3-го самолета (Н): ";
    cin >> Air3.Cl;

    Air1.L = 0.5 * Ro * Air1.V * Air1.V * Air1.S * Air1.Cl;
    Air2.L = 0.5 * Ro * Air2.V * Air2.V * Air2.S * Air2.Cl;
    Air3.L = 0.5 * Ro * Air3.V * Air3.V * Air3.S * Air3.Cl;

    Air1.D = 0.5 * Ro * Air1.V * Air1.V * Air1.S * Air1.Cp;
    Air2.D = 0.5 * Ro * Air2.V * Air2.V * Air2.S * Air2.Cp;
    Air3.D = 0.5 * Ro * Air3.V * Air3.V * Air3.S * Air3.Cp;

    Air1.a = (Air1.T - Air1.D) / Air1.m;
    Air2.a = (Air2.T - Air2.D) / Air2.m;
    Air3.a = (Air3.T - Air3.D) / Air3.m;

    Air1.ay = (Air1.L - Air1.m * g) / Air1.m;
    Air2.ay = (Air2.L - Air2.m * g) / Air2.m;
    Air3.ay = (Air3.L - Air3.m * g) / Air3.m;

    double h;
    cout << "Введите высоту (м): ";
    cin >> h;
    Air1.t = sqrt(2 * h / Air1.ay);
    Air2.t = sqrt(2 * h / Air2.ay);
    Air3.t = sqrt(2 * h / Air3.ay);
    if (Air1.ay > 0 and Air2.ay > 0 and Air3.ay > 0 and h > 0) {
        if (Air1.t > Air2.t and Air1.t > Air3.t) {
            cout << "Первый самолет быстрее наберет высоту, за " << Air1.t << " секунд" << endl;
        }
        else if (Air2.t > Air1.t and Air2.t > Air3.t) {
            cout << "Второй самолет быстрее наберет высоту, за " << Air2.t << " секунд" << endl;
        }
        else if (Air3.t > Air1.t and Air3.t > Air2.t) {
            cout << "Третий самолет быстрее наберет высоту, за " << Air1.t << " секунд" << endl;
        }
    }
    else {
        cout << "Данные введены не верно!" << endl;
    }

	return 0;
}