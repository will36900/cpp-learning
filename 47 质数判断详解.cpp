#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

/*
 * ==========================================
 *     质数判断详解 - 从入门到优化
 * ==========================================
 *
 * 什么是质数（素数）？
 * - 只能被1和自己整除的大于1的自然数
 * - 例如：2, 3, 5, 7, 11, 13, 17, 19, 23, 29...
 * - 1不是质数，2是最小的质数（也是唯一的偶数质数）
 */

// ==========================================
// 方法1：最基础的暴力法（效率最低）
// ==========================================
bool isPrime_v1(int n) {
    // 思路：从2试到n-1，看有没有能整除n的数

    if (n <= 1) return false;  // 1和负数不是质数
    if (n == 2) return true;   // 2是质数

    // 从2开始，一直试到n-1
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {  // 如果n能被i整除
            return false;   // 说明n不是质数
        }
    }
    return true;  // 所有数都试过了，都不能整除，是质数
}

// ==========================================
// 方法2：优化1 - 只需要试到 n/2
// ==========================================
bool isPrime_v2(int n) {
    // 思路：n的因数不可能大于n/2（除了n自己）
    // 例如：10的因数是1,2,5,10，最大的因数5=10/2

    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;  // 排除偶数

    // 只需要试到n/2
    for (int i = 3; i <= n / 2; i += 2) {  // i+=2 跳过偶数
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// ==========================================
// 方法3：优化2 - 只需要试到 √n（最常用）
// ==========================================
bool isPrime_v3(int n) {
    // 思路：如果n有因数，必定一个≤√n，一个≥√n
    // 例如：36 = 6×6，49 = 7×7，100 = 10×10
    //       12 = 3×4（3<√12，4>√12）
    // 所以只需要试到√n就够了！

    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;  // 排除偶数

    // 只需要试到√n
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// ==========================================
// 方法4：再优化 - 避免重复计算sqrt
// ==========================================
bool isPrime_v4(int n) {
    // 优化：不在循环中反复调用sqrt(n)
    // 改用 i*i <= n，效果一样但更快

    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    // 用 i*i <= n 代替 i <= sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// ==========================================
// 方法5：终极优化 - 只检查 6k±1 的数
// ==========================================
bool isPrime_v5(int n) {
    // 数学技巧：所有质数都可以表示为 6k±1 的形式
    // （除了2和3）
    //
    // 为什么？
    // - 6k能被6整除，不是质数
    // - 6k+2能被2整除，不是质数
    // - 6k+3能被3整除，不是质数
    // - 6k+4能被2整除，不是质数
    // 只有 6k+1 和 6k+5(即6k-1) 可能是质数

    if (n <= 1) return false;
    if (n <= 3) return true;  // 2和3是质数
    if (n % 2 == 0 || n % 3 == 0) return false;  // 排除2和3的倍数

    // 只检查 6k±1 形式的数
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// ==========================================
// 辅助函数：详细展示判断过程
// ==========================================
void showProcess(int n) {
    cout << "\n【详细判断 " << n << " 是否为质数】" << endl;
    cout << "-----------------------------------" << endl;

    if (n <= 1) {
        cout << n << " ≤ 1，不是质数" << endl;
        return;
    }
    if (n == 2) {
        cout << "2 是最小的质数（唯一的偶数质数）" << endl;
        return;
    }
    if (n % 2 == 0) {
        cout << n << " 是偶数，能被2整除，不是质数" << endl;
        return;
    }

    cout << "需要检查的范围：3 到 √" << n << " ≈ " << (int)sqrt(n) << endl;
    cout << "检查过程：" << endl;

    for (int i = 3; i <= sqrt(n); i += 2) {
        cout << "  " << n << " ÷ " << i << " = " << (double)n/i;
        if (n % i == 0) {
            cout << " ✗ 能整除！" << n << " = " << i << " × " << n/i << endl;
            cout << "结论：" << n << " 不是质数" << endl;
            return;
        } else {
            cout << " ✓ 不能整除，余数=" << n % i << endl;
        }
    }

    cout << "结论：" << n << " 是质数！" << endl;
}

// ==========================================
// 性能测试函数
// ==========================================
void performanceTest(int n) {
    cout << "\n【性能测试】找出1到" << n << "之间的所有质数" << endl;
    cout << "========================================" << endl;

    clock_t start, end;
    int count;

    // 测试方法1
    start = clock();
    count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime_v1(i)) count++;
    }
    end = clock();
    cout << "方法1（暴力法）：找到 " << count << " 个质数，耗时 "
         << (double)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;

    // 测试方法2
    start = clock();
    count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime_v2(i)) count++;
    }
    end = clock();
    cout << "方法2（试到n/2）：找到 " << count << " 个质数，耗时 "
         << (double)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;

    // 测试方法3
    start = clock();
    count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime_v3(i)) count++;
    }
    end = clock();
    cout << "方法3（试到√n）：找到 " << count << " 个质数，耗时 "
         << (double)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;

    // 测试方法4
    start = clock();
    count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime_v4(i)) count++;
    }
    end = clock();
    cout << "方法4（i*i优化）：找到 " << count << " 个质数，耗时 "
         << (double)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;

    // 测试方法5
    start = clock();
    count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime_v5(i)) count++;
    }
    end = clock();
    cout << "方法5（6k±1优化）：找到 " << count << " 个质数，耗时 "
         << (double)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
}

// ==========================================
// 找出范围内的所有质数
// ==========================================
void findPrimesInRange(int start, int end) {
    cout << "\n【" << start << " 到 " << end << " 之间的质数】" << endl;
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (isPrime_v5(i)) {  // 用最优方法
            cout << i << " ";
            count++;
            if (count % 10 == 0) cout << endl;  // 每10个换行
        }
    }
    cout << "\n共有 " << count << " 个质数" << endl;
}

// ==========================================
// 主函数
// ==========================================
int main() {
    cout << "==========================================" << endl;
    cout << "    质数判断详解与优化" << endl;
    cout << "==========================================" << endl;

    // 1. 基础测试
    cout << "\n【基础测试】" << endl;
    int testNumbers[] = {1, 2, 7, 15, 17, 25, 29, 100, 97};
    for (int num : testNumbers) {
        cout << num << " 是质数吗？" << (isPrime_v5(num) ? "是✓" : "否✗") << endl;
    }

    // 2. 详细过程演示
    showProcess(17);  // 质数
    showProcess(24);  // 合数
    showProcess(97);  // 较大的质数

    // 3. 找出范围内的质数
    findPrimesInRange(1, 100);

    // 4. 性能对比测试
    performanceTest(10000);

    // 5. 知识总结
    cout << "\n==========================================" << endl;
    cout << "💡 质数判断核心知识点" << endl;
    cout << "==========================================" << endl;
    cout << "1. 定义：只能被1和自己整除的数（>1）" << endl;
    cout << "2. 2是唯一的偶数质数" << endl;
    cout << "3. 优化思路：只需试到√n" << endl;
    cout << "   原因：因数成对出现，一个≤√n，一个≥√n" << endl;
    cout << "4. 跳过偶数：i += 2（除了2，偶数都不是质数）" << endl;
    cout << "5. 高级优化：只检查6k±1形式的数" << endl;
    cout << "6. 时间复杂度：" << endl;
    cout << "   - 暴力法：O(n)" << endl;
    cout << "   - 优化到√n：O(√n)" << endl;
    cout << "==========================================" << endl;

    // 6. 实战应用
    cout << "\n【实战应用】" << endl;
    cout << "找出第10个质数：";
    int count = 0, num = 2;
    while (count < 10) {
        if (isPrime_v5(num)) {
            count++;
            if (count == 10) cout << num << endl;
        }
        num++;
    }

    cout << "找出大于100的第一个质数：";
    num = 101;
    while (!isPrime_v5(num)) {
        num++;
    }
    cout << num << endl;

    return 0;
}

/*
 * ==========================================
 * 🎯 练习题
 * ==========================================
 *
 * 1. 写一个函数：判断一个数是否为孪生质数
 *    （孪生质数：相差2的两个质数，如3和5，11和13）
 *    bool isTwinPrime(int n);
 *
 * 2. 写一个函数：找出n的所有质因数
 *    （例如：24 = 2×2×2×3，质因数是2,2,2,3）
 *    void primeFactors(int n);
 *
 * 3. 写一个函数：判断哥德巴赫猜想
 *    （任何大于2的偶数都能表示为两个质数之和）
 *    void goldbach(int n);  // 例如：8=3+5, 10=3+7=5+5
 *
 * 4. 写一个函数：埃氏筛法求质数
 *    （更高效的批量求质数方法）
 *
 * 继续加油！💪
 */
