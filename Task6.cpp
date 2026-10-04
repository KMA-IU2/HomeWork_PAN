#include <locale.h>	
#include <iostream>
#include <iomanip> // Для красивого форматирования таблицы
using namespace std;


int S = 125;
float Cl = 0.5;

int main() {
	setlocale(0, "russian");
	int size;
	cout << "Введите раазмер массива ( количество скоростей и плотнростей воздуха): ";
	cin >> size;
	double *V = new double[size];
	double *Ro = new double[size];
	cout << "Введите " << size << " значений скорости через Enter: " << endl;
	for (int i = 0; i < size; i++) {
		cin >> V[i];
	}
	
	cout << "Введите " << size << " значений плотностей воздуха через Enter: " << endl;
	for (int i = 0; i < size; i++) {
		cin >> Ro[i];
	}
	
	double* L = new double[size];
	for (int i = 0 ; i < size; i++) {
		L[i] = 0.5 * Ro[i] * V[i] * V[i] * S * Cl;
	}


	cout << "----------------------------------------------------" << endl;
	cout << "| " << setw(4) << "Шаг"
		<< " | " << setw(10) << "Скорость"
		<< " | " << setw(10) << "Плотность"
		<< " | " << setw(15) << "Подъемная сила" << " |" << endl;
	cout << "----------------------------------------------------" << endl;

	for (int i = 0; i < size; i++) {
		cout << "| " << setw(4) << i + 1
			<< " | " << setw(10) << fixed << setprecision(2) << V[i]
			<< " | " << setw(10) << Ro[i]
			<< " | " << setw(15) << L[i] << " |" << endl;
	}
	cout << "----------------------------------------------------" << endl;

	return 0;
}