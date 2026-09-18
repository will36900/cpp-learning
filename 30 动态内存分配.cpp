#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "请输入数组长度：";

    if (!(cin >> n) || n <= 0) {
        cout << "数组长度必须是正整数\n";
        return 1;
    }

    int* arr = new int[n]{};  // 申请 n 个整数，全部初始化为 0

    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    delete[] arr;  // 释放整个数组
    arr = nullptr;
}