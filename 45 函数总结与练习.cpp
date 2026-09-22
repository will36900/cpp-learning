/*
 * ========================================
 *     C++ 函数完整学习指南
 * ========================================
 */

#include <iostream>
using namespace std;

// ==========================================
// 📚 函数知识点总结
// ==========================================

/*
1. 【函数的基本概念】
   - 函数是完成特定任务的代码块
   - 可以重复使用，避免代码重复
   - 让程序结构更清晰，更容易维护

2. 【函数的四个组成部分】
   ① 返回类型：int, double, void, string 等
   ② 函数名：遵循变量命名规则
   ③ 参数列表：可以有0个或多个参数
   ④ 函数体：用{}包裹的代码块

   格式：
   返回类型 函数名(参数类型 参数名, ...) {
       // 函数体
       return 返回值;  // void类型不需要return
   }

3. 【函数声明 vs 函数定义】
   - 声明：告诉编译器函数存在（只写函数头）
     int add(int a, int b);

   - 定义：实现函数的具体功能
     int add(int a, int b) {
         return a + b;
     }

4. 【参数传递方式】
   ① 值传递（默认）：传递副本，不影响原变量
      void change(int x) { x = 100; }

   ② 引用传递：传递引用，会修改原变量
      void change(int &x) { x = 100; }

   ③ const引用：只读，不能修改
      void print(const string &s) { ... }

5. 【特殊类型函数】
   - void函数：无返回值
   - 默认参数：void func(int x = 10)
   - 函数重载：同名不同参数
   - 递归函数：函数调用自己

6. 【函数的作用域】
   - 局部变量：函数内定义，只在函数内有效
   - 全局变量：函数外定义，所有函数都能访问（尽量少用）
   - 参数：也是局部变量

7. 【常见应用场景】
   - 数学计算：加减乘除、幂运算、最大公约数
   - 判断验证：是否为偶数、是否为质数、输入验证
   - 数据处理：数组排序、查找、统计
   - 字符串操作：转换大小写、计数、查找
   - 工具函数：交换、打印、菜单显示
*/

// ==========================================
// 💡 实用练习题
// ==========================================

// 练习1：写一个函数判断一个数是否为完全平方数
bool isPerfectSquare(int num) {
    if (num < 0) return false;
    for (int i = 0; i * i <= num; i++) {
        if (i * i == num) return true;
    }
    return false;
}

// 练习2：写一个函数反转字符串
string reverseString(string str) {
    string result = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        result += str[i];
    }
    return result;
}

// 练习3：写一个函数计算数组中所有正数的和
int sumPositive(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }
    return sum;
}

// 练习4：写一个函数判断一个字符串是否为回文
bool isPalindrome(string str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// 练习5：写一个函数找出数组中第二大的数
int findSecondMax(int arr[], int size) {
    if (size < 2) return -1;

    int max1 = arr[0], max2 = -1;
    for (int i = 1; i < size; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }
    return max2;
}

// 练习6：写一个函数计算n的n次方
long long powerN(int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= n;
    }
    return result;
}

// ==========================================
// 🎯 主函数：运行所有练习
// ==========================================
int main() {
    cout << "=== C++函数综合练习 ===" << endl << endl;

    // 练习1
    cout << "【练习1】判断完全平方数：" << endl;
    cout << "16是完全平方数吗？" << (isPerfectSquare(16) ? "是" : "否") << endl;
    cout << "15是完全平方数吗？" << (isPerfectSquare(15) ? "是" : "否") << endl;
    cout << "100是完全平方数吗？" << (isPerfectSquare(100) ? "是" : "否") << endl << endl;

    // 练习2
    cout << "【练习2】反转字符串：" << endl;
    cout << "Hello → " << reverseString("Hello") << endl;
    cout << "C++编程 → " << reverseString("C++编程") << endl << endl;

    // 练习3
    cout << "【练习3】数组正数求和：" << endl;
    int arr1[] = {-5, 3, -2, 8, 10, -1, 7};
    cout << "数组：-5, 3, -2, 8, 10, -1, 7" << endl;
    cout << "正数之和：" << sumPositive(arr1, 7) << endl << endl;

    // 练习4
    cout << "【练习4】判断回文字符串：" << endl;
    cout << "racecar是回文吗？" << (isPalindrome("racecar") ? "是" : "否") << endl;
    cout << "hello是回文吗？" << (isPalindrome("hello") ? "是" : "否") << endl;
    cout << "abba是回文吗？" << (isPalindrome("abba") ? "是" : "否") << endl << endl;

    // 练习5
    cout << "【练习5】找第二大的数：" << endl;
    int arr2[] = {45, 23, 67, 12, 89, 34};
    cout << "数组：45, 23, 67, 12, 89, 34" << endl;
    cout << "第二大的数：" << findSecondMax(arr2, 6) << endl << endl;

    // 练习6
    cout << "【练习6】计算n的n次方：" << endl;
    cout << "2² = " << powerN(2) << endl;
    cout << "3³ = " << powerN(3) << endl;
    cout << "4⁴ = " << powerN(4) << endl;
    cout << "5⁵ = " << powerN(5) << endl << endl;

    // 知识点回顾
    cout << "========================================" << endl;
    cout << "🎓 C++函数学习要点：" << endl;
    cout << "========================================" << endl;
    cout << "1. 函数让代码可重用、更清晰" << endl;
    cout << "2. 值传递 vs 引用传递要分清" << endl;
    cout << "3. 函数可以调用函数（包括自己-递归）" << endl;
    cout << "4. 函数重载：同名不同参" << endl;
    cout << "5. 先想清楚函数要做什么，再写代码" << endl;
    cout << "6. 给函数起有意义的名字" << endl;
    cout << "7. 一个函数只做一件事" << endl;
    cout << "========================================" << endl;

    return 0;
}

/*
 * ==========================================
 * 🔥 进阶挑战题（自己尝试）
 * ==========================================
 *
 * 1. 写一个函数：冒泡排序数组
 *    void bubbleSort(int arr[], int size);
 *
 * 2. 写一个函数：二分查找（数组已排序）
 *    int binarySearch(int arr[], int size, int target);
 *
 * 3. 写一个函数：汉诺塔问题（递归）
 *    void hanoi(int n, char from, char to, char aux);
 *
 * 4. 写一个函数：判断两个字符串是否为字母异位词
 *    bool isAnagram(string s1, string s2);
 *
 * 5. 写一个函数：帕斯卡三角形第n行
 *    void pascalTriangle(int n);
 *
 * 加油！多练习才能掌握函数！💪
 */
