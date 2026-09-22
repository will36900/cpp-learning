#include <iostream>
using namespace std;

/*
 * ==========================================
 *     函数概念对比与易错点
 * ==========================================
 */

// ==========================================
// 【对比1】值传递 vs 引用传递（最重要！）
// ==========================================

void demonstrateValuePass() {
    cout << "\n【值传递示例】" << endl;
    cout << "----------------------------" << endl;

    // 值传递函数
    auto changeValue = [](int x) {
        cout << "  函数内修改前：x = " << x << endl;
        x = 999;
        cout << "  函数内修改后：x = " << x << endl;
    };

    int num = 10;
    cout << "调用前：num = " << num << endl;
    changeValue(num);
    cout << "调用后：num = " << num << " ← 没变！" << endl;
    cout << "💡 值传递：传的是副本，不影响原变量" << endl;
}

void demonstrateReferencePass() {
    cout << "\n【引用传递示例】" << endl;
    cout << "----------------------------" << endl;

    // 引用传递函数
    auto changeReference = [](int &x) {
        cout << "  函数内修改前：x = " << x << endl;
        x = 999;
        cout << "  函数内修改后：x = " << x << endl;
    };

    int num = 10;
    cout << "调用前：num = " << num << endl;
    changeReference(num);
    cout << "调用后：num = " << num << " ← 改变了！" << endl;
    cout << "💡 引用传递：传的是引用（地址），会修改原变量" << endl;
}

// ==========================================
// 【对比2】return vs void
// ==========================================

// 有返回值
int addWithReturn(int a, int b) {
    return a + b;  // 返回结果
}

// 无返回值（直接输出）
void addWithVoid(int a, int b) {
    cout << "结果：" << (a + b) << endl;  // 不返回，直接打印
}

// ==========================================
// 【对比3】局部变量 vs 全局变量
// ==========================================

int globalVar = 100;  // 全局变量：所有函数都能访问

void showScope() {
    int localVar = 50;  // 局部变量：只在这个函数内有效

    cout << "\n【变量作用域】" << endl;
    cout << "----------------------------" << endl;
    cout << "全局变量 globalVar = " << globalVar << endl;
    cout << "局部变量 localVar = " << localVar << endl;

    globalVar = 200;  // 可以修改全局变量
    cout << "修改后全局变量 = " << globalVar << endl;
}

// ==========================================
// 【对比4】函数重载：参数不同
// ==========================================

void print(int x) {
    cout << "整数：" << x << endl;
}

void print(double x) {
    cout << "小数：" << x << endl;
}

void print(string x) {
    cout << "字符串：" << x << endl;
}

void print(int x, int y) {
    cout << "两个整数：" << x << ", " << y << endl;
}

// ==========================================
// 【对比5】递归 vs 循环
// ==========================================

// 用递归计算1+2+3+...+n
int sumRecursive(int n) {
    if (n == 1) return 1;  // 基本情况
    return n + sumRecursive(n - 1);  // 递归调用
}

// 用循环计算1+2+3+...+n
int sumLoop(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// ==========================================
// 【易错点演示】
// ==========================================

void commonMistakes() {
    cout << "\n【常见易错点】" << endl;
    cout << "==========================================" << endl;

    // 易错点1：忘记return
    cout << "\n❌ 错误：有返回值的函数忘记return" << endl;
    cout << "int add(int a, int b) {" << endl;
    cout << "    a + b;  // 忘记写return！" << endl;
    cout << "}" << endl;
    cout << "✅ 正确：int add(int a, int b) { return a + b; }" << endl;

    // 易错点2：void函数用return
    cout << "\n❌ 错误：void函数返回值" << endl;
    cout << "void print() {" << endl;
    cout << "    return 10;  // void不能返回值！" << endl;
    cout << "}" << endl;
    cout << "✅ 正确：void print() { cout << 10; } 或改为 int print() { return 10; }" << endl;

    // 易错点3：数组传递误解
    cout << "\n⚠️  注意：数组传递实际是引用传递！" << endl;
    cout << "void change(int arr[]) { arr[0] = 999; }" << endl;
    cout << "会修改原数组！虽然看起来像值传递" << endl;

    // 易错点4：函数声明与定义不一致
    cout << "\n❌ 错误：声明和定义参数不匹配" << endl;
    cout << "声明：int add(int a, int b);" << endl;
    cout << "定义：int add(int x) { ... }  // 参数个数不同！" << endl;
    cout << "✅ 正确：保证声明和定义完全一致" << endl;
}

// ==========================================
// 【何时使用引用传递？】
// ==========================================

void whenToUseReference() {
    cout << "\n【何时使用引用传递？】" << endl;
    cout << "==========================================" << endl;
    cout << "✅ 需要修改原变量时" << endl;
    cout << "   void swap(int &a, int &b)" << endl;
    cout << "" << endl;
    cout << "✅ 传递大对象避免拷贝（加const）" << endl;
    cout << "   void print(const string &str)  // string很大" << endl;
    cout << "" << endl;
    cout << "✅ 需要返回多个值" << endl;
    cout << "   void divide(int a, int b, int &q, int &r)" << endl;
    cout << "" << endl;
    cout << "❌ 传递基本类型且不需要修改" << endl;
    cout << "   void calc(int x)  // 用值传递即可" << endl;
}

// ==========================================
// 主函数
// ==========================================
int main() {
    cout << "==========================================" << endl;
    cout << "    C++ 函数核心概念对比" << endl;
    cout << "==========================================" << endl;

    // 1. 值传递 vs 引用传递
    demonstrateValuePass();
    demonstrateReferencePass();

    // 2. return vs void
    cout << "\n【return vs void】" << endl;
    cout << "----------------------------" << endl;
    int result = addWithReturn(5, 3);
    cout << "有返回值：可以赋值给变量 result = " << result << endl;
    cout << "无返回值：";
    addWithVoid(5, 3);

    // 3. 作用域
    showScope();
    cout << "main中访问全局变量 = " << globalVar << " ← 被函数修改了" << endl;
    // cout << localVar;  // 错误！局部变量在函数外不可访问

    // 4. 函数重载
    cout << "\n【函数重载】" << endl;
    cout << "----------------------------" << endl;
    cout << "同名函数print()，根据参数自动选择：" << endl;
    print(42);
    print(3.14);
    print("Hello");
    print(10, 20);

    // 5. 递归 vs 循环
    cout << "\n【递归 vs 循环】" << endl;
    cout << "----------------------------" << endl;
    cout << "计算1+2+3+...+10" << endl;
    cout << "递归方式：" << sumRecursive(10) << endl;
    cout << "循环方式：" << sumLoop(10) << endl;
    cout << "💡 结果相同，但循环通常更快更省内存" << endl;

    // 易错点
    commonMistakes();

    // 使用建议
    whenToUseReference();

    // 总结
    cout << "\n==========================================" << endl;
    cout << "📌 记住这些核心区别：" << endl;
    cout << "==========================================" << endl;
    cout << "1. 值传递（默认）vs 引用传递（加&）" << endl;
    cout << "2. 有返回值（return）vs 无返回值（void）" << endl;
    cout << "3. 局部变量（函数内）vs 全局变量（函数外）" << endl;
    cout << "4. 函数重载：同名不同参数" << endl;
    cout << "5. 递归：函数调用自己" << endl;
    cout << "==========================================" << endl;

    return 0;
}
