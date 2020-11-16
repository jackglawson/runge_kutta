#include <vector>
#include <iostream>
using namespace std;

void rhs_eval(double x, vector<double> y, vector<double>& dydx) {
	dydx[0] = 2 * x;
	dydx[1] = 3 * pow(x, 2);
}


void rk4_adaptive_step(double& x, vector<double>& y,
	void (*rhs_eval)(double, vector<double>, vector<double>&),
	double& h, double& t_err, double acc,
	double S, int& rept, int maxrept,
	double h_min, double h_max, int flag);

void rk4_fixed_step(double& x, vector<double>& y, void (*rhs_eval)(double, vector<double>, vector<double>&), double h);


void main() {
	vector<double> y{ 1, 1 };
	double x{ 0 };
	double h{ 0.001 };
	double t_err;	
	int rept{ 1 };


	double acc{ 0.001 };
	double S{ 10 };
	double max_rept{ 10 };
	double h_min{ 0.001 };
	double h_max{ 1 };
	int flag{ 2 };

	for (int i{ 0 }; i < 10; i++) {
		std::cout << "x: " << x << "\n";
		std::cout << "y: ";
		for (int j{ 0 }; j < y.size(); j++) {
			std::cout << y[j] << " ";
		}
		std::cout << "\n\n";

		//rk4_fixed(x, y, rhs_eval, h);
		rk4_adaptive_step(x, y, rhs_eval, h, t_err, acc, S, rept, max_rept, h_min, h_max, flag);
	}


	
}