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
auto func4 = [](double x) { return x*x*x + 4*x*x + 3*x + 5; }; // 只取分子

int main() {
    cout << "----------------------B" << endl;
    BisectionSolver bisection;
    // （1）
    Init* init_b1 = new Init(0, Pi*0.5, func1);
    vector<double> result1 = bisection.solve(init_b1);
    cout << "Question1:" << endl
        << "root: " << result1[0] 
        << ", width of interval: " << result1[1] 
        << ", maximum iterative count: " << result1[2] << endl;
    cout << "---------" << endl;

    // （2）
    Init* init_b2 = new Init(0, 1, func2);
    vector<double> result2 = bisection.solve(init_b2);
    cout << "Question2:" << endl
        << "root: " << result2[0] 
        << ", width of interval: " << result2[1] 
        << ", maximum iterative count: " << result2[2] << endl;
    cout << "---------" << endl;

    //（3）
    Init* init_b3 = new Init(1, 3, func3);
    vector<double> result3 = bisection.solve(init_b3);
    cout << "Question3:" << endl
        << "root: " << result3[0] 
        << ", width of interval: " << result3[1] 
        << ", maximum iterative count: " << result3[2] << endl;
    cout << "---------" << endl;

    //（4）
    cout << "Question4: " << endl;
    Init* init_b4 = new Init(0, 4, func4);
    vector<double> result4 = bisection.solve(init_b4);
    cout << "root: " << result4[0] 
        << ", width of interval: " << result4[1] 
        << ", maximum iterative count: " << result4[2] << endl;
    cout << "---------" << endl;

    delete init_b1, init_b2, init_b3, init_b4;
    return 0;
}