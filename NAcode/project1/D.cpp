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
    vector<double> result1 = secant.solve(0, Pi*0.5, func1);
    cout << "Question1:" << endl
        << "x_{n}: " << result1[0] 
        << ", x_{n-1}: " << result1[1] 
        << ", maximum iterative count: " << result1[2] << endl;
    cout << "---------" << endl;
    vector<double> result2 = secant.solve(1, 1.4, func2);
    cout << "Question2:" << endl
        << "x_{n}: " << result2[0] 
        << ", x_{n-1}: " << result2[1] 
        << ", maximum iterative count: " << result2[2] << endl;
    cout << "---------" << endl;
    vector<double> result3 = secant.solve(0, -0.5, func3);
    cout << "Question3:" << endl
        << "x_{n}: " << result3[0] 
        << ", x_{n-1}: " << result3[1] 
        << ", maximum iterative count: " << result3[2] << endl;
    cout << "---------" << endl;
    return 0;
}