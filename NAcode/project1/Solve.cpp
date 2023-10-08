#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include "Solve.h"
using namespace std;

int sgn(double x) {
    if(x > 0)
        return 1;
    else if(x == 0)
        return 0;
    return -1;
}

// // 此构造函数适用于二分法和割线法
Init::Init(double x0, double x1, function<double(double)> func)
    : x0(x0), x1(x1), func(func) { }

Init::Init(double x0, function<double(double)> func, function<double(double)> dfunc)
    :  x0(x0), func(func), dfunc(dfunc) { }

vector<double> BisectionSolver::solve(Init* init)
{
    double left = init->x0, right = init->x1;
    function<double(double)> func = init->func;
    if(sgn(func(left)) == sgn(func(right))) {
        cout << "Error for preconditions: sgn(f(a)) == sgn(f(b))" << endl;
        return {0, 0, 0};
    }
    // 设定精度、区间长度、最大迭代次数
    double epsilon = 1e-5, delta = 1e-5, M = 1000;
    double width = right - left;
    double value = func(left);
    double root, froot;
    double iter_cnt;
    for(iter_cnt = 0; iter_cnt < M; ++iter_cnt) {
        width = width / 2;
        root = left + width;
        if(fabs(width) < delta)
            break;
        froot = func(root);
        if(fabs(froot) < epsilon)
            break;
        else if(sgn(froot) == sgn(value))
            left = root;
    }
    return {root, width, iter_cnt};
}

vector<double> NewtonSolver::solve(Init* init)
{
    double x0 = init->x0;
    function<double(double)> func = init->func, dfunc = init->dfunc;
    // 设定精度、最大迭代次数
    double epsilon = 1e-5, M = 1000;
    double x = x0, fx, dfx;
    double iter_cnt = 0;
    for(; iter_cnt < M; ++iter_cnt) {
        fx = func(x);
        if(fabs(fx) < epsilon)
            break;
        dfx = dfunc(x);
        x = x - fx/dfx;
    }
    return {x, iter_cnt};
}

vector<double> SecantSolver::solve(Init* init)
{
    double x0 = init->x0, x1 = init->x1;
    function<double(double)> func = init->func;
    // 设定精度、区间长度、最大迭代次数
    double epsilon = 1e-5, delta = 1e-5, M = 1000;
    double fx0 = func(x0), fx1 = func(x1);
    double iter_cnt = 1;
    // 定义斜率的倒数
    double slope;
    for(; iter_cnt < M; ++iter_cnt) {
        slope = (x1 - x0) / (fx1 - fx0);
        x0 = x1;
        fx0 = fx1;
        x1 = x1 - fx1 * slope;
        if(fabs(x1 - x0) < delta)
            break;
        fx1 = func(x1);
        if(fabs(fx1) < epsilon)
            break;
    }
    return {x1, x0, iter_cnt};
}