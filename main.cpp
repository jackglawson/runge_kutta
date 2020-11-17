#include <iostream>
#include "rk4_step.h"


vector<double> walk_to(double x_from, double x_to, vector<double> y0, void (*rhs_eval)(double, vector<double>, vector<double>&));


void rhs_eval(double x, vector<double> y, vector<double>& dydx) {
	dydx[0] = 2 * x;
	dydx[1] = 3 * pow(x, 2);
}


int main() {
	double x_from{ 0 };
	double x_to{ 4 };
	vector<double> y0{ 0, 0 };

	vector<double> y = walk_to(x_from, x_to, y0, rhs_eval);

	cout << "y = ";
	for (int i{ 0 }; i < y.size(); i++) {
		cout << y[i] << ", ";
	}
	return 0;
}
