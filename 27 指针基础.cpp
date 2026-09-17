#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* p = &a;

    cout << a << "\n";   // 10
    cout << &a << "\n";  // a 的地址
    cout << p << "\n";   // 和上面相同的地址
    cout << *p << "\n";  // 10
}