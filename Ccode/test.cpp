#include<iostream>
using namespace std;
class A{
public:
A(){f();}
virtual void f(){cout<<"A::f()"<<endl;}
};
class B:public A{
public:
B(){f();}
void f(){cout<<"B::f()"<<endl;}
};
int main()
{
A a;
a.f();
B b;
b.f();
}
