/*
  Function to advance set of coupled first-order o.d.e.s by single step
  using fixed step-length fourth-order Runge-Kutta scheme

     x        ... independent variable
     y        ... array of dependent variables
     h        ... fixed step-length

  Requires right-hand side routine

     void rhs_eval (double x, Array<double,1> y, Array<double,1>& dydx)

  which evaluates derivatives of y (w.r.t. x) in array dydx
*/

#include <vector>
using namespace std;

void rk4_fixed_step(double& x, vector<double>& y, void (*rhs_eval)(double, vector<double>, vector<double>&), double h){
    // Array y assumed to be of extent n, where n is no. of coupled
    // equations
    int n = y.size();

    // Declare local arrays
    vector<double> k1(n), k2(n), k3(n), k4(n), f(n), dydx(n);

    // Zeroth intermediate step 
    (*rhs_eval) (x, y, dydx);
    for (int j = 0; j < n; j++)
    {
        k1[j] = h * dydx[j];
        f[j] = y[j] + k1[j] / 2.;
    }

    // First intermediate step 
    (*rhs_eval) (x + h / 2., f, dydx);
    for (int j = 0; j < n; j++)
    {
        k2[j] = h * dydx[j];
        f[j] = y[j] + k2[j] / 2.;
    }

    // Second intermediate step
    (*rhs_eval) (x + h / 2., f, dydx);
    for (int j = 0; j < n; j++)
    {
        k3[j] = h * dydx[j];
        f[j] = y[j] + k3[j];
    }

    // Third intermediate step 
    (*rhs_eval) (x + h, f, dydx);
    for (int j = 0; j < n; j++)
    {
        k4[j] = h * dydx[j];
    }

    // Actual step 
    for (int j = 0; j < n; j++)
    {
        y[j] += k1[j] / 6. + k2[j] / 3. + k3[j] / 3. + k4[j] / 6.;
    }
    x += h;

    return;
}