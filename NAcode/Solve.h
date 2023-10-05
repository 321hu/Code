#ifndef _SOLVE_HEADER_
#define _SOVLE_HEADER_

#include <iostream>
#include <math.h>
#include <functional>
using namespace std;

// void hu();

class EquationSolver
{
public:
    virtual double solve();

};

class BisectionSolver : virtual public EquationSolver
{
public:
    double solve(double left, double right, function<double(double)> func);
};

class NewtonSolver : virtual public EquationSolver
{
public:
    double solve();
};


class SecantSolver : virtual public EquationSolver
{
public:
    double solve();
};
#endif