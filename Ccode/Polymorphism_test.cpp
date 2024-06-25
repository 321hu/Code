#include<iostream>

using namespace std;

class Base {
public:
    virtual void func() {
        cout << "Base::func" << endl;
    }
private:
    int _b;
};

class Derive : public Base {
public:
    virtual void func() {
        cout << "Derive::func" << endl;
    }
private:
    int _d;
};

void Func(Base &a) {
    a.func();
}

template<typename T>
void swap_(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    // 第一种实现方式
    // Base b;
    // Derive d;
    // Func(b);
    // Func(d);

    // 第二种实现方式
    Base* b; // 如果只有这一句代码，则b->func();将无法运行
    Derive d;
    b = &d;
    b->func();

    double a1 = 1.1, a2 = 2.2;
    cout << a1 << " " << a2 << endl;
    swap_<double>(a1, a2);
    cout << a1 << " " << a2;
    return 0;
}