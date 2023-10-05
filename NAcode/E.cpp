#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include "Solve.h"

#define Pi M_PI

using namespace std;

// 经估计，根大概在0.15-0.20之间
auto func = [](double h) { return 5*Pi - 10*asin(h) - 10*h*sqrt(1-h*h) - 12.4; };
auto dfunc = [](double h) { return -20.0/sqrt(1-h*h); };

int main() {
    double L = 10, r = 1, V = 12.4;
    cout << "----------------------" << endl;
    // 二分法取区间为[0, 1]
    BisectionSolver bisection;
    vector<double> result1 = bisection.solve(0, 1, func);
    cout << "Bisection:" << endl
        << "root: " << result1[0] 
        << ", width of interval: " << result1[1] 
        << ", maximum iterative count: " << result1[2] << endl;
    cout << "---------" << endl;
    // 牛顿迭代法取x0 = 0.15
    NewtonSolver newton;
    vector<double> result2 = newton.solve(0.15, func, dfunc);
    cout << "Newton, x0 = 0.15:" << endl
        << "root: " << result2[0]
        << ", maximum iterative count: " << result2[1] << endl;
    cout << "---------" << endl;
    // 割线法取x0 = 0，x1 = 0.5
    SecantSolver secant;
    vector<double> result3 = secant.solve(0, 0.5, func);
    cout << "Secant:" << endl
        << "x_{n}: " << result3[0] 
        << ", x_{n-1}: " << result3[1] 
        << ", maximum iterative count: " << result3[2] << endl;
    cout << "---------" << endl;
    return 0;
}