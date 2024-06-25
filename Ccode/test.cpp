#include<iostream>
#include<map>
using namespace std;

int main() {
	map<int, int> m{{1, 2}, {2, 2}, {1, 2}, {8, 2}, {6, 2}};//有序
    for(map<int, int>::iterator iter= m.begin(); iter != m.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }

	for(const auto it : m) {
        cout << it.first << " " << it.second << endl;
    }
	return 0;
}


// class A
// {
// public:
//     int b;
//     // A(int _b) : b(_b) { }
// };

// class B : public A
// {
// public:
//     int b;
//     B(int _b) : b(_b) { }
//     // B(int _b) : A(_b) { }
// };

// int main() {
//     A* bb = new B(1);
//     cout << bb->b << endl;
//     return 0;
// }