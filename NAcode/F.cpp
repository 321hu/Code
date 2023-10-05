#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include "Solve.h"

#define Pi M_PI

using namespace std;

int main() {
    cout << "----------------------" << endl;
    //（a）
    double beta1 = 11.5 * Pi / 180.0, l = 89, h = 49, D = 55;
    double A = l*sin(beta1), B = l*cos(beta1), 
        C = (h+0.5*D)*sin(beta1) - 0.5*D*tan(beta1),
        E = (h+0.5*D)*cos(beta1) - 0.5*D;
    auto func_a = [A, B, C, E](double x) {
        return A*sin(x)*cos(x) + B*sin(x)*sin(x) - C*cos(x) - E*sin(x);
    };
    BisectionSolver bisection;
    vector<double> result1 = bisection.solve(0, Pi*0.25, func_a);
    cout << "(a)alpha = " << result1[0] * 180.0 / Pi << endl;
    cout << "---------" << endl;
    // （b）
    double D_b = 30;
    double C_b = (h+0.5*D_b)*sin(beta1) - 0.5*D_b*tan(beta1),
        E_b = (h+0.5*D_b)*cos(beta1) - 0.5*D_b;


    // cout << C << " " << E << endl << C_b << " " << E_b << endl;

    auto func_b = [A, B, C_b, E_b](double x) {
        return A*sin(x)*cos(x) + B*sin(x)*sin(x) - C_b*cos(x) - E_b*sin(x);
    };
    auto dfunc_b = [A, B, C_b, E_b](double x) {
        return A*cos(2*x) + B*sin(2*x) + C_b*sin(x) - E_b*cos(x);
    };
    NewtonSolver newton;
    double x0 = 33*Pi/180.0;
    vector<double> result2 = newton.solve(x0, func_b, dfunc_b);
    cout << "(b)Newton, x0 = " << x0 << endl
        << "alpha = " << result2[0] * 180.0 / Pi << endl;
    cout << "---------" << endl;
    // （c）
    SecantSolver secant;
    double x1 = 6000*Pi/180.0;
    // double x1 = 60*Pi/180.0;
    vector<double> result3 = secant.solve(x0, x1, func_b);
    cout << "(c)Secant, x0 = " << x0 << ", x1 = " << x1 << endl
        << "x_{n}: " << result3[0] * 180.0 / Pi
        << ", x_{n-1}: " << result3[1] * 180.0 / Pi << endl;
    cout << "---------" << endl;
    return 0;
}