#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// ============ 12. 返回多个值（通过引用参数）============
void divideWithRemainder(int dividend, int divisor, int &quotient, int &remainder) {
    quotient = dividend / divisor;
    remainder = dividend % divisor;
}

// ============ 13. 返回布尔值（判断函数）============
bool isEven(int num) {
    return num % 2 == 0;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// ============ 14. 字符串处理函数 ============
string toUpperCase(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;  // 转大写
        }
    }
    return str;
}

int countVowels(const string &str) {
    int count = 0;
    for (char c : str) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

// ============ 15. 数组处理函数 ============
int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

double calculateAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// ============ 16. 数学工具函数 ============
int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int gcd(int a, int b) {  // 最大公约数（欧几里得算法）
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// ============ 17. 菜单驱动函数 ============
void showMenu() {
    cout << "\n==== 计算器菜单 ====" << endl;
    cout << "1. 加法" << endl;
    cout << "2. 减法" << endl;
    cout << "3. 乘法" << endl;
    cout << "4. 除法" << endl;
    cout << "0. 退出" << endl;
    cout << "请选择：";
}

double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0;
        default: return 0;
    }
}

// ============ 18. 输入验证函数 ============
bool isValidAge(int age) {
    return age >= 0 && age <= 150;
}

bool isValidEmail(const string &email) {
    // 简单验证：包含@和.
    bool hasAt = false, hasDot = false;
    for (char c : email) {
        if (c == '@') hasAt = true;
        if (c == '.') hasDot = true;
    }
    return hasAt && hasDot;
}

// ============ 主函数 ============
int main() {
    cout << "=== C++函数实战技巧 ===" << endl << endl;

    // 12. 返回多个值
    cout << "12. 返回多个值（通过引用参数）：" << endl;
    int q, r;
    divideWithRemainder(17, 5, q, r);
    cout << "17 ÷ 5 = " << q << " 余 " << r << endl << endl;

    // 13. 布尔判断函数
    cout << "13. 布尔判断函数：" << endl;
    cout << "8是偶数吗？" << (isEven(8) ? "是" : "否") << endl;
    cout << "7是偶数吗？" << (isEven(7) ? "是" : "否") << endl;
    cout << "17是质数吗？" << (isPrime(17) ? "是" : "否") << endl;
    cout << "18是质数吗？" << (isPrime(18) ? "是" : "否") << endl << endl;

    // 14. 字符串处理
    cout << "14. 字符串处理函数：" << endl;
    string text = "Hello World";
    cout << "原文：" << text << endl;
    cout << "大写：" << toUpperCase(text) << endl;
    cout << "元音字母个数：" << countVowels(text) << endl << endl;

    // 15. 数组处理
    cout << "15. 数组处理函数：" << endl;
    int numbers[] = {45, 23, 67, 12, 89, 34};
    int size = 6;
    cout << "数组：";
    for (int i = 0; i < size; i++) cout << numbers[i] << " ";
    cout << endl;
    cout << "最大值：" << findMax(numbers, size) << endl;
    cout << "平均值：" << calculateAverage(numbers, size) << endl;
    reverseArray(numbers, size);
    cout << "反转后：";
    for (int i = 0; i < size; i++) cout << numbers[i] << " ";
    cout << endl << endl;

    // 16. 数学工具函数
    cout << "16. 数学工具函数：" << endl;
    cout << "2的5次方 = " << power(2, 5) << endl;
    cout << "48和18的最大公约数 = " << gcd(48, 18) << endl << endl;

    // 17. 计算器示例
    cout << "17. 计算器函数：" << endl;
    cout << "10 + 5 = " << calculate(10, 5, '+') << endl;
    cout << "10 - 5 = " << calculate(10, 5, '-') << endl;
    cout << "10 × 5 = " << calculate(10, 5, '*') << endl;
    cout << "10 ÷ 5 = " << calculate(10, 5, '/') << endl << endl;

    // 18. 输入验证
    cout << "18. 输入验证函数：" << endl;
    cout << "年龄25有效吗？" << (isValidAge(25) ? "有效" : "无效") << endl;
    cout << "年龄200有效吗？" << (isValidAge(200) ? "有效" : "无效") << endl;
    cout << "test@example.com有效吗？" << (isValidEmail("test@example.com") ? "有效" : "无效") << endl;
    cout << "testexample.com有效吗？" << (isValidEmail("testexample.com") ? "有效" : "无效") << endl;

    return 0;
}
