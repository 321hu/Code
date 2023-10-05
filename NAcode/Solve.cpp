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

vector<double> EquationSolver::solve() {
    return {};
}

vector<double> BisectionSolver::solve(double left, double right, 
                function<double(double)> func)
{
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

vector<double> NewtonSolver::solve(double x0, 
                function<double(double)> func, function<double(double)> dfunc)
{
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

vector<double> SecantSolver::solve(double x_0, double x_1, 
                function<double(double)> func)
{
    // 设定精度、区间长度、最大迭代次数
    double epsilon = 1e-5, delta = 1e-5, M = 1000;
    double x0 = x_0, x1 = x_1;
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