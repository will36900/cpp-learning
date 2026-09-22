#include <iostream>
using namespace std;


int main() {
    int n;
    cout << "请输入数组长度：";

    if (!(cin >> n) || n <= 0) {
        cout << "数组长度必须是正整数\n";
        return 1;
    }

    // arr 是指针变量的名字，不是数组变量的名字；也可以改名为 ptr。
    // new int[n]{} 创建包含 n 个整数的动态数组，全部初始化为 0，返回首元素的地址。
    // int* arr 定义一个指针，保存这个地址：arr → 动态数组的第一个元素。
    // 对比：int arr[3]; 定义的是数组；这里的 int* arr 定义的是指针。
    // 动态数组没有单独的变量名，我们通过 arr 访问它。
    int* arr = new int[n]{};

    for (int i = 0; i < n; i++) {
        // 指针也能使用下标：arr[i] 等价于 *(arr + i)。
        // arr + i 找到第 i 个下标对应的元素，* 访问该元素，这里给它赋值。
        arr[i] = (i + 1) * 10;
    
    }

    for (int i = 0; i < n; i++) {
        // 通过指针读取动态数组中的元素；能使用 [i] 不代表 arr 本身是数组。
        cout << arr[i] << " ";
    }
    cout << "\n";

    delete[] arr;  // 与 new[] 配对，释放整个动态数组，不是删除指针变量 arr。
    arr = nullptr;  // arr 仍然存在；将它设为空指针，避免保留已经失效的地址。
}
