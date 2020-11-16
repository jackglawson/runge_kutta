#include "params.h"
#include "rk4_step.h"
#include "rk4.h"


void rhs_eval(double x, vector<double> y, vector<double>& dydx) {
	dydx[0] = 2 * x;
	dydx[1] = 3 * pow(x, 2);
}


int main() {
	double x_from{ 0 };
	double x_to{ 10 };
	vector<double> y0{ 0, 0 };
	Result result;
	result = integrate(x_from, x_to, y0, rhs_eval);
	result.print();

	return 0;
}
