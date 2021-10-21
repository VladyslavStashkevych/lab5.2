// lab5.2.cpp
// <Сташкевич Владислав>
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора за допомогою функцій.
// Варіант 19

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double Sum(const double x, int &n, const double eps);
double ElementA(const double x, int n, double &a);

int main() {
	double xFirst, xLast, x, dx, eps, sum;
	int n = 1;

	cout << "Enter first x: ";	cin >> xFirst;
	cout << "Enter last x: ";	cin >> xLast;
	cout << "Enter dx: ";	cin >> dx;
	cout << "Enter eps: ";	cin >> eps;

	cout << fixed;
	cout << "-------------------------------------------------\n";
	cout << "|" << setw(7) << "x" << " |"
		<< setw(10) << "arcsin(x)" << " |"
		<< setw(10) << "Sum" << " |"
		<< setw(5) << "n" << " |\n";
	cout << "-------------------------------------------------\n";

	for (x = xFirst; x <= xLast; x += dx) {
		sum = Sum(x, n, eps);

		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << asin(x) << " |"
			<< setw(10) << setprecision(5) << sum << " |"
			<< setw(5) << n << " |\n";
	}

	cout << "-------------------------------------------------\n";

	return 0;
}

double Sum(const double x, int &n, const double eps) {
	double a = 1, sum;
	
	for (a = pow(x, 3) / 6., n = 2, sum = x + a; abs(a) >= eps; n++) {
		sum += ElementA(x, n, a);
	}

	return sum;
}

double ElementA(const double x, int n, double &a) {
	double R;

	R = pow((2 * n - 1) * x, 2) / (2. * n * (2 * n + 1));
	a *= R;

	return a;
}