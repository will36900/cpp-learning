#include <iostream>
#include <cmath>
using namespace std;

/*
 * ==========================================
 *     质数判断 - 图解与原理深度剖析
 * ==========================================
 */

// ==========================================
// 核心问题：为什么只需要检查到 √n ？
// ==========================================
void whySqrtN() {
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║  为什么只需要检查到 √n？           ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    cout << "\n【关键洞察】因数总是成对出现！" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    int n = 36;
    cout << "\n以 36 为例，它的所有因数对：" << endl;
    cout << "  1  × 36 = 36" << endl;
    cout << "  2  × 18 = 36" << endl;
    cout << "  3  × 12 = 36" << endl;
    cout << "  4  ×  9 = 36" << endl;
    cout << "  6  ×  6 = 36  ← 中间点 √36 = 6" << endl;
    cout << "  9  ×  4 = 36  ← 和上面重复了！" << endl;
    cout << " 12  ×  3 = 36" << endl;
    cout << " 18  ×  2 = 36" << endl;
    cout << " 36  ×  1 = 36" << endl;

    cout << "\n观察规律：" << endl;
    cout << "  • √36 = 6 是分界线" << endl;
    cout << "  • 6 之前的因数：1, 2, 3, 4, 6" << endl;
    cout << "  • 6 之后的因数：6, 9, 12, 18, 36" << endl;
    cout << "  • 每个小于√n的因数，都有一个大于√n的配对因数" << endl;
    cout << "  • 所以只需检查到√n，就能发现所有因数对！" << endl;

    cout << "\n【数学证明】" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "假设 n 有因数 a 和 b，使得 a × b = n" << endl;
    cout << "如果 a > √n 并且 b > √n" << endl;
    cout << "那么 a × b > √n × √n = n" << endl;
    cout << "这与 a × b = n 矛盾！" << endl;
    cout << "所以至少有一个因数 ≤ √n" << endl;
}

// ==========================================
// 图解：不同数字的检查范围
// ==========================================
void visualizeRange() {
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║  不同方法的检查范围对比            ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    int numbers[] = {17, 100, 1000};

    for (int n : numbers) {
        cout << "\n判断 " << n << " 是否为质数：" << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

        int range1 = n - 2;
        int range2 = n / 2 - 1;
        int range3 = (int)sqrt(n) - 1;

        cout << "  暴力法：检查 2 到 " << (n-1) << "，共 " << range1 << " 次" << endl;
        cout << "  优化1：检查 2 到 " << (n/2) << "，共 " << range2 << " 次" << endl;
        cout << "  优化2：检查 2 到 √" << n << "=" << (int)sqrt(n)
             << "，共 " << range3 << " 次 ⭐" << endl;

        double ratio = (double)range1 / range3;
        cout << "  效率提升：" << ratio << " 倍！" << endl;
    }
}

// ==========================================
// 图解：6k±1 优化原理
// ==========================================
void explain6kPlus1() {
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║  6k±1 优化原理（高级技巧）         ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    cout << "\n【观察】除了2和3，所有质数都可以表示为 6k±1" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    cout << "\n任何整数都可以表示为以下6种形式之一：" << endl;
    cout << "┌────────┬──────────┬────────────┐" << endl;
    cout << "│ 形式   │ 示例     │ 分析       │" << endl;
    cout << "├────────┼──────────┼────────────┤" << endl;
    cout << "│ 6k     │ 6,12,18  │ 能被6整除  │" << endl;
    cout << "│ 6k+1   │ 7,13,19  │ 可能是质数 ✓│" << endl;
    cout << "│ 6k+2   │ 8,14,20  │ 能被2整除  │" << endl;
    cout << "│ 6k+3   │ 9,15,21  │ 能被3整除  │" << endl;
    cout << "│ 6k+4   │ 10,16,22 │ 能被2整除  │" << endl;
    cout << "│ 6k+5   │ 11,17,23 │ 可能是质数 ✓│" << endl;
    cout << "└────────┴──────────┴────────────┘" << endl;

    cout << "\n注意：6k+5 = 6k-1 = 6(k+1)-1" << endl;
    cout << "所以只需检查 6k±1 形式的数！" << endl;

    cout << "\n【前30个数的分析】" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    for (int i = 1; i <= 30; i++) {
        int mod = i % 6;
        string form;
        bool needCheck = false;

        if (mod == 0) form = "6k";
        else if (mod == 1) { form = "6k+1 ⭐"; needCheck = true; }
        else if (mod == 2) form = "6k+2";
        else if (mod == 3) form = "6k+3";
        else if (mod == 4) form = "6k+4";
        else { form = "6k+5 ⭐"; needCheck = true; }

        bool isPrime = (i == 2 || i == 3);
        if (!isPrime && i > 1) {
            isPrime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }

        cout << i << "\t" << form << "\t";
        if (isPrime) cout << "质数 ✓";
        else if (needCheck) cout << "合数";
        cout << endl;
    }

    cout << "\n结论：除了2和3，只需检查 6k±1 的数！" << endl;
}

// ==========================================
// 实战对比：三种方法检查同一个数
// ==========================================
void compareThreeMethods(int n) {
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║  实战对比：判断 " << n << " 是否为质数" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    // 方法1：暴力法
    cout << "\n【方法1：暴力法】检查所有数从 2 到 " << (n-1) << endl;
    cout << "检查：";
    int count1 = 0;
    for (int i = 2; i < n && count1 < 20; i++) {
        cout << i << " ";
        count1++;
    }
    if (n - 2 > 20) cout << "... (共" << (n-2) << "个)";
    cout << endl;

    // 方法2：优化到√n
    cout << "\n【方法2：优化到√n】检查到 " << (int)sqrt(n) << endl;
    cout << "检查：";
    for (int i = 2; i <= sqrt(n); i++) {
        cout << i << " ";
    }
    cout << " (共" << ((int)sqrt(n)-1) << "个)" << endl;

    // 方法3：6k±1
    cout << "\n【方法3：6k±1优化】只检查 6k±1 形式" << endl;
    cout << "检查：2 3 ";
    int count3 = 2;
    for (int i = 5; i * i <= n; i += 6) {
        cout << i << " " << (i+2) << " ";
        count3 += 2;
    }
    cout << " (共约" << count3 << "个)" << endl;

    cout << "\n效率对比：";
    cout << "\n  暴力法：" << (n-2) << " 次检查";
    cout << "\n  √n优化：" << ((int)sqrt(n)-1) << " 次检查";
    cout << "\n  6k±1优化：约 " << count3 << " 次检查 ⭐最快" << endl;
}

// ==========================================
// 常见误区
// ==========================================
void commonMistakes() {
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║  常见误区与注意事项                ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    cout << "\n❌ 误区1：忘记处理特殊情况" << endl;
    cout << "   • 1 不是质数（要特判）" << endl;
    cout << "   • 2 是质数（唯一的偶数质数）" << endl;
    cout << "   • 负数不是质数" << endl;

    cout << "\n❌ 误区2：循环条件写错" << endl;
    cout << "   错误：for (int i = 2; i < sqrt(n); i++)  // 应该是 <=" << endl;
    cout << "   正确：for (int i = 2; i <= sqrt(n); i++)" << endl;
    cout << "   或者：for (int i = 2; i * i <= n; i++)" << endl;

    cout << "\n❌ 误区3：重复计算 sqrt(n)" << endl;
    cout << "   慢速：for (int i = 2; i <= sqrt(n); i++)  // 每次都算" << endl;
    cout << "   快速：for (int i = 2; i * i <= n; i++)    // 只算一次乘法" << endl;

    cout << "\n❌ 误区4：没有及早返回" << endl;
    cout << "   应该找到一个因数就立即 return false" << endl;
    cout << "   不要继续检查剩余的数" << endl;

    cout << "\n✅ 最佳实践模板：" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << R"(
bool isPrime(int n) {
    if (n <= 1) return false;          // 特判
    if (n <= 3) return true;           // 2和3是质数
    if (n % 2 == 0 || n % 3 == 0)      // 排除2和3的倍数
        return false;

    for (int i = 5; i * i <= n; i += 6) {  // 6k±1优化
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
)" << endl;
}

// ==========================================
// 主函数
// ==========================================
int main() {
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║     质数判断原理图解               ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    // 1. 核心原理：为什么√n
    whySqrtN();

    // 2. 检查范围对比
    visualizeRange();

    // 3. 6k±1优化原理
    explain6kPlus1();

    // 4. 实战对比
    compareThreeMethods(101);

    // 5. 常见误区
    commonMistakes();

    // 6. 总结
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║  🎯 核心要点总结                   ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "\n1️⃣  质数定义：只能被1和自己整除的数（>1）" << endl;
    cout << "\n2️⃣  为什么√n：因数成对出现，只需检查一半" << endl;
    cout << "   36 = 1×36, 2×18, 3×12, 4×9, 6×6" << endl;
    cout << "        └─小的─┘  └─大的─┘" << endl;
    cout << "        只需检查到 √36=6" << endl;
    cout << "\n3️⃣  优化技巧：" << endl;
    cout << "   • 排除偶数：i += 2" << endl;
    cout << "   • 用 i*i <= n 代替 i <= sqrt(n)" << endl;
    cout << "   • 6k±1：只检查这种形式的数" << endl;
    cout << "\n4️⃣  时间复杂度：" << endl;
    cout << "   • O(n)     → O(√n)     → O(√n/3)" << endl;
    cout << "   • 暴力法   → √n优化   → 6k±1优化" << endl;
    cout << "\n5️⃣  记住特殊情况：1不是，2是唯一偶数质数" << endl;
    cout << "\n════════════════════════════════════════" << endl;

    return 0;
}
