#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include "Solve.h"
using namespace std;

/**
 * @brief 计算sng(x)
 * @return 返回x的符号数值
*/
int sgn(double x) {
    if(x > 0)
        return 1;
    else if(x == 0)
        return 0;
    return -1;
}

// 此构造函数适用于二分法和割线法
Init::Init(double x0, double x1, function<double(double)> func)
    : x0(x0), x1(x1), func(func) { }

// 此构造函数适用于牛顿迭代法
Init::Init(double x0, function<double(double)> func, function<double(double)> dfunc)
    :  x0(x0), func(func), dfunc(dfunc) { }

/**
 * @brief 二分法对应求解函数
 * @return 返回{根、区间长度、最大迭代次数}
*/
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

/**
 * @brief 牛顿迭代法对应求解函数
 * @return 返回{根、最大迭代次数}
*/
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

/**
 * @brief 割线法对应求解函数
 * @return 返回{x_{n}，x_{n-1}，最大迭代次数}
*/
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