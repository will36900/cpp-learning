#include <iostream>
using namespace std;

// ============ 6. 函数原型声明（函数声明） ============
// 可以先声明函数，稍后再定义，这样可以把main放在前面
int multiply(int a, int b);  // 函数声明
void printArray(int arr[], int size);

// ============ 7. 默认参数 ============
// 从右往左设置默认值
void printMessage(string msg, int times = 1) {
    for (int i = 0; i < times; i++) {
        cout << msg << endl;
    }
}

// ============ 8. 函数重载（Overloading）============
// 同名函数，但参数不同
int max(int a, int b) {
    return (a > b) ? a : b;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

// ============ 9. 引用传递 vs 值传递 ============
void changeByValue(int x) {
    x = 100;  // 不会影响原变量
}

void changeByReference(int &x) {
    x = 100;  // 会修改原变量
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// ============ 10. const参数（只读参数）============
void printPerson(const string &name, int age) {
    // name = "改不了";  // 错误！const参数不能修改
    cout << "姓名：" << name << "，年龄：" << age << endl;
}

// ============ 11. 递归函数 ============
int factorial(int n) {
    if (n <= 1) {
        return 1;  // 基本情况
    }
    return n * factorial(n - 1);  // 递归调用
}

// 斐波那契数列
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// ============ 主函数 ============
int main() {
    cout << "=== C++函数进阶概念 ===" << endl << endl;

    // 6. 函数原型
    cout << "6. 函数原型（在文件末尾定义）：" << endl;
    cout << "5 × 3 = " << multiply(5, 3) << endl;
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 5);
    cout << endl;

    // 7. 默认参数
    cout << "7. 默认参数：" << endl;
    printMessage("Hello");  // 使用默认值1
    printMessage("你好", 3);  // 指定打印3次
    cout << endl;

    // 8. 函数重载
    cout << "8. 函数重载：" << endl;
    cout << "max(5, 10) = " << max(5, 10) << endl;
    cout << "max(3.5, 2.1) = " << max(3.5, 2.1) << endl;
    cout << "max(5, 10, 3) = " << max(5, 10, 3) << endl;
    cout << endl;

    // 9. 值传递 vs 引用传递
    cout << "9. 值传递 vs 引用传递：" << endl;
    int num1 = 10;
    changeByValue(num1);
    cout << "值传递后 num1 = " << num1 << " (没变)" << endl;

    int num2 = 10;
    changeByReference(num2);
    cout << "引用传递后 num2 = " << num2 << " (改变了)" << endl;

    int x = 5, y = 8;
    cout << "交换前：x=" << x << ", y=" << y << endl;
    swap(x, y);
    cout << "交换后：x=" << x << ", y=" << y << endl;
    cout << endl;

    // 10. const参数
    cout << "10. const参数（只读）：" << endl;
    printPerson("李四", 25);
    cout << endl;

    // 11. 递归函数
    cout << "11. 递归函数：" << endl;
    cout << "5的阶乘 = " << factorial(5) << endl;
    cout << "斐波那契数列前8项：";
    for (int i = 0; i < 8; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}

// ============ 函数定义（在main之后）============
int multiply(int a, int b) {
    return a * b;
}

void printArray(int arr[], int size) {
    cout << "数组元素：";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
