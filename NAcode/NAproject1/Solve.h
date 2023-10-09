#ifndef _SOLVE_HEADER_
#define _SOVLE_HEADER_

#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
using namespace std;

int sgn(double x);

/**
 * @brief 用于存放参数的类
*/
class Init 
{
public:
    double x0, x1;
    function<double(double)> func, dfunc;
    Init(double left, double right, function<double(double)> func);
    Init(double x0, function<double(double)> func, function<double(double)> dfunc);
};

class EquationSolver
{
public:
    virtual vector<double> solve(Init* init) = 0; // pure virtual function
};

class BisectionSolver : public EquationSolver
{
public:
    vector<double> solve(Init* init);
};

class NewtonSolver : virtual public EquationSolver
{
public:
    vector<double> solve(Init* init);
    
};

class SecantSolver : virtual public EquationSolver
{
public:
    vector<double> solve(Init* init);
};

#endif