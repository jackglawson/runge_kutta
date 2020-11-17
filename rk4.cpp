#include <iostream>
#include <iomanip>
#include <vector>
#include "rk4_step.h"
#include "params.h"
using namespace std;

vector<double> walk_to(double x_from, double x_to, vector<double> y0, void (*rhs_eval)(double, vector<double>, vector<double>&)) {
    double h{ p::h_min };
    double t_err{ 0 };
    int rept{ 0 };

    double x{ x_from };
    vector<double> y{ y0 };

    while (x < x_to) {
        rk4_adaptive_step(x, y, rhs_eval, h, t_err, p::acc, p::S, rept, p::maxrept, p::h_min, p::h_max, p::flag);
        cout << "Stepping to x = " << x << "\n";
    }
    cout << "Stepping back by " << x - x_to << "\n\n";
    rk4_fixed_step(x, y, rhs_eval, x_to - x);

    return y;
}


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