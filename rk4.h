#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "rk4_step.h"
#include "params.h"
using namespace std;


struct Result {
    vector<double> x;
    vector<vector<double>> y;

    void print();
}; 


Result integrate(double x_from, double x_to, vector<double> y0, void (*rhs_eval)(double, vector<double>, vector<double>&));
