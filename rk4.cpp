#include "rk4.h"

void Result::print() {
    cout << left;
    cout << setw(10) << "x" << setw(10) << "y" << "\n";
    for (int i{ 0 }; i < x.size(); i++) {
        cout << setw(10) << x[i];
        for (int j{ 0 }; j < y[0].size(); j++) {
            cout << setw(10) << y[i][j];
        }
        cout << "\n";
    }
}



Result integrate(double x_from, double x_to, vector<double> y0, void (*rhs_eval)(double, vector<double>, vector<double>&)) {
    double h{ p::h_min };
    double t_err{ 0 };
    int rept{ 0 };

    double x{ x_from };
    vector<double> y{ y0 };

    Result result;
    result.y.push_back(y);
    result.x.push_back(x);

    while (x < x_to) {
        rk4_adaptive_step(x, y, rhs_eval, h, t_err, p::acc, p::S, rept, p::maxrept, p::h_min, p::h_max, p::flag);
        result.y.push_back(y);
        result.x.push_back(x);
    }

    return result;
}