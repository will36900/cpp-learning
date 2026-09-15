#include <iostream>
using namespace std;
int main(){
    short num1 = 10;
    cout << "Size of short: " << sizeof(num1) << " bytes" << endl;
    float f1 = 3.14f;
    cout << "Size of float: " << sizeof(f1) << " bytes" << endl;

// 浮点型 float（7位有效数字） double（15-16位有效数字） long double（15-19位有效数字）
// 科学计数法
    float f2 = 3e2; // 3 * 10^2 = 300
    float f3 = 3e-2; // 3 * 10^-2 = 0.03
    cout << "f2 = " << f2 << endl;
    cout << "f3 = " << f3 << endl;
    return 0;
}