#ifndef _SOLVE_HEADER_
#define _SOVLE_HEADER_

#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
using namespace std;

// void hu();

int sgn(double x);

class EquationSolver
{
public:
    virtual vector<double> solve();

};

class BisectionSolver : virtual public EquationSolver
{
public:
    vector<double> solve(double left, double right, 
                function<double(double)> func);
};

class NewtonSolver : virtual public EquationSolver
{
public:
    vector<double> solve(double x0, function<double(double)> func, 
                function<double(double)> dfunc);
};


class SecantSolver : virtual public EquationSolver
{
public:
    vector<double> solve(double x0, double x1, 
                function<double(double)> func);
};
#endif