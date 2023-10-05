#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include "Solve.h"

#define Pi M_PI

using namespace std;

auto func1 = [](double x) { return 1.0/x - tan(x); };
auto func2 = [](double x) { return 1.0/x - pow(2, x); };
auto func3 = [](double x) { return pow(2, -x) + exp(x) + 2*cos(x) - 6; };
auto func4 = [](double x) { return x*x*x + 4*x*x + 3*x + 5; }; // 只取分母

int main() {
    cout << "----------------------" << endl;
    BisectionSolver bisection;
    vector<double> result1 = bisection.solve(0, Pi*0.5, func1);
    cout << "Question1:" << endl
        << "root: " << result1[0] 
        << ", width of interval: " << result1[1] 
        << ", maximum iterative count: " << result1[2] << endl;
    cout << "---------" << endl;
    vector<double> result2 = bisection.solve(0, 1, func2);
    cout << "Question1:" << endl
        << "root: " << result2[0] 
        << ", width of interval: " << result2[1] 
        << ", maximum iterative count: " << result2[2] << endl;
    cout << "---------" << endl;
    vector<double> result3 = bisection.solve(1, 3, func3);
    cout << "Question1:" << endl
        << "root: " << result3[0] 
        << ", width of interval: " << result3[1] 
        << ", maximum iterative count: " << result3[2] << endl;
    cout << "---------" << endl;
    vector<double> result4 = bisection.solve(-4, 0, func4);
    cout << "Question1:" << endl
        << "root: " << result4[0] 
        << ", width of interval: " << result4[1] 
        << ", maximum iterative count: " << result4[2] << endl;
    cout << "---------" << endl;
    return 0;
}