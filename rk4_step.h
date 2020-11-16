#pragma once

#include <vector>
using namespace std;

void rk4_fixed_step(double& x, vector<double>& y, void (*rhs_eval)(double, vector<double>, vector<double>&), double h);

void rk4_adaptive_step(double& x, vector<double>& y,
    void (*rhs_eval)(double, vector<double>, vector<double>&),
    double& h, double& t_err, double acc,
    double S, int& rept, int maxrept,
    double h_min, double h_max, int flag);