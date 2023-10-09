#include<iostream>
#include<math.h>
using namespace std;


class A
{
public:
    int b;
    // A(int _b) : b(_b) { }
};

class B : public A
{
public:
    int b;
    B(int _b) : b(_b) { }
    // B(int _b) : A(_b) { }
};

int main() {
    A* bb = new B(1);
    cout << bb->b << endl;
    return 0;
}

// BisectionInit* init = new BisectionInit();这个值是对的，但无法输入Init*作为的参数里
// Init* init = new BisectionInit();这个值是错的