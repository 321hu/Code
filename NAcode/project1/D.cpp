#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include "Solve.h"

#define Pi M_PI

using namespace std;

auto func1 = [](double x) { return sin(x*0.5) - 1; };
auto func2 = [](double x) { return exp(x) - tan(x); };
auto func3 = [](double x) { return x*x*x - 12*x*x + 3*x + 1; };

int main() {
    cout << "----------------------D" << endl;
    SecantSolver secant;
    Init* init_d1 = new Init(0, Pi*0.5, func1);
    vector<double> result1 = secant.solve(init_d1);
    cout << "Question1:" << endl
        << "x_{n}: " << result1[0] 
        << ", x_{n-1}: " << result1[1] 
        << ", maximum iterative count: " << result1[2] << endl;
    cout << "---------" << endl;
    Init* init_d2 = new Init(1, 1.4, func2);
    vector<double> result2 = secant.solve(init_d2);
    cout << "Question2:" << endl
        << "x_{n}: " << result2[0] 
        << ", x_{n-1}: " << result2[1] 
        << ", maximum iterative count: " << result2[2] << endl;
    cout << "---------" << endl;
    Init* init_d3 = new Init(0, -0.5, func3);
    vector<double> result3 = secant.solve(init_d3);
    cout << "Question3:" << endl
        << "x_{n}: " << result3[0] 
        << ", x_{n-1}: " << result3[1] 
        << ", maximum iterative count: " << result3[2] << endl;
    cout << "---------" << endl;

    delete init_d1, init_d2, init_d3;
    return 0;
}