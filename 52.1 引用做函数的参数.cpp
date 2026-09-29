#include <iostream>
using namespace std;

// 1. 值传递：交换的是副本，不会改变 main 中的 a 和 b
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "函数内：a = " << a << ", b = " << b << '\n';
}

// 2. 地址传递：通过指针修改原变量
void swapByAddress(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3. 引用传递：直接修改原变量
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 1, b = 2;

    swapByValue(a, b);
    cout << "值传递后：a = " << a << ", b = " << b << "\n\n";

    swapByAddress(&a, &b);  // &a、&b：传入地址
    cout << "地址传递后：a = " << a << ", b = " << b << "\n\n";

    swapByReference(a, b);
    cout << "引用传递后：a = " << a << ", b = " << b << '\n';

    return 0;
}
