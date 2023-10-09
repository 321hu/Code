#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include "Solve.h"

#define Pi M_PI

using namespace std;

auto func = [](double x) { return tan(x) - x; };
auto dfunc = [](double x) { return 1.0/(cos(x)*cos(x)) - 1; };

int main() {
    cout << "----------------------C" << endl;
    NewtonSolver newton;
    Init* init_c1 = new Init(4.5, func, dfunc);
    vector<double> result1 = newton.solve(init_c1);
    cout << "x0 = 4.5:" << endl
        << "root: " << result1[0]
        << ", maximum iterative count: " << result1[1] << endl;
    cout << "---------" << endl;
    Init* init_c2 = new Init(7.7, func, dfunc);
    vector<double> result2 = newton.solve(init_c2);
    cout << "x0 = 7.7:" << endl
        << "root: " << result2[0]
        << ", maximum iterative count: " << result2[1] << endl;
    cout << "---------" << endl;

    delete init_c1, init_c2;
    return 0;
}