#include <iostream>
#include <math.h>
#include <functional>
#include "Solve.h"
using namespace std;

// void hu() {
//     cout << "hello!" << endl;
// }

double EquationSolver::solve() {
    return 0;
}

double BisectionSolver::solve(double left, double right, function<double(double)> func) {
    double epsilon = 0.001, delta = 0.01, M = 1000;

}

double NewtonSolver::solve() {

}

double SecantSolver::solve() {
    
}