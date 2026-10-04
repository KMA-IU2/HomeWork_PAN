#include <locale.h>	
#include <iostream>
using namespace std;

int main(){	
setlocale(0, "russian");
double g = 9.80665;
double m;
double L;
double D;
double T;
cout << "Введите массу самолета (кг): ";
cin >> m;
cout << "Введите подъемную силу (Н): ";
cin >> L;
cout << "Введите силу сопротивления (Н): ";
cin >> D;
cout << "Введите тягу двигаателя (Н): ";
cin >> T;

double a = (T - D) / m;
double ay = (L - m * g) / m; 
cout << "Ускорение по направлению движения = " << a << "м/с^2" << endl;
cout << "Вертикальное ускорение = " << ay << "м/с^2";

return 0;
}