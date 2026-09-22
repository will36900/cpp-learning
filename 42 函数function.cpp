#include <iostream>
using namespace std;

// ============ 1. 最简单的函数：无参数，无返回值 ============
void sayHello() {
    cout << "Hello, World!" << endl;
}

// ============ 2. 有参数，无返回值 ============
void greet(string name) {
    cout << "你好，" << name << "！" << endl;
}

// ============ 3. 有参数，有返回值 ============
int add(int a, int b) {
    return a + b;
}

// ============ 4. 多个参数 ============
double calculateArea(double length, double width) {
    return length * width;
}

// ============ 5. 函数可以调用其他函数 ============
int square(int x) {
    return x * x;
}

int sumOfSquares(int a, int b) {
    return square(a) + square(b);  // 调用上面的square函数
}

// ============ 主函数 ============
int main() {
    cout << "=== C++函数入门示例 ===" << endl << endl;

    // 1. 调用无参数函数
    cout << "1. 无参数函数：" << endl;
    sayHello();
    cout << endl;

    // 2. 调用有参数函数
    cout << "2. 有参数函数：" << endl;
    greet("小明");
    greet("张三");
    cout << endl;

    // 3. 有返回值的函数
    cout << "3. 有返回值函数：" << endl;
    int sum = add(5, 3);
    cout << "5 + 3 = " << sum << endl;
    cout << "10 + 20 = " << add(10, 20) << endl;  // 直接在cout中使用
    cout << endl;

    // 4. 多个参数
    cout << "4. 多参数函数：" << endl;
    double area = calculateArea(5.5, 3.2);
    cout << "长5.5，宽3.2的面积 = " << area << endl;
    cout << endl;

    // 5. 函数调用函数
    cout << "5. 函数调用其他函数：" << endl;
    cout << "3² = " << square(3) << endl;
    cout << "3² + 4² = " << sumOfSquares(3, 4) << endl;

    return 0;
}
