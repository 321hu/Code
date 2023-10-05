#include <iostream>
#include <functional>
#include <math.h>
#include "Solve.h"
using namespace std;

// int main() {
//     // hu();
//     return 0;
// }

double executeFunction(std::function<double(double)> func, double value) {
    return func(value);
}
// 使用Lambda表达式定义一个匿名函数，该Lambda接受一个int参数并输出它
auto myLambda = [](double x) {
        return x * x;
    };
int main() {
    double value = 4;

    // 将Lambda表达式作为参数传递给executeFunction
    cout << executeFunction(myLambda, value) << endl;

    return 0;
}