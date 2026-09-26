#include <iostream>
using namespace std;
// 三种方式：1. static关键字 2. new int[]（自己删除内存）3. 声明全局变量
// 普通数组不能直接按值返回，这里返回的都是数组首元素的地址。
// 不同函数中的 arr 属于不同作用域，互不冲突；同一作用域内不能重复定义同名变量。

// 方法1：static局部数组，函数结束后数组仍然存在。
int *getStaticArray() {
    static int arr[3] = {10, 20, 30};
    return arr; // 相当于 return &arr[0];
}

// 方法2：动态分配数组，函数结束后内存仍然存在。
// 调用者使用完后必须用 delete[] 释放。
int *getDynamicArray() {
    int *arr = new int[3]{40, 50, 60};
    return arr;
}

// 方法3：全局数组，在整个程序运行期间都存在。
int globalArray[3] = {70, 80, 90};

int *getGlobalArray() {
    return globalArray;
}

// 指针不包含数组长度，因此需要另外传入长度。
void printArray(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int *arr1 = getStaticArray();
    cout << "static数组：";
    printArray(arr1, 3);

    int *arr2 = getDynamicArray();
    cout << "动态数组：";
    printArray(arr2, 3);
    delete[] arr2; // new[] 必须搭配 delete[]，不能只写 delete。
    arr2 = nullptr; // 释放后不能再通过原地址访问数组。

    int *arr3 = getGlobalArray();
    cout << "全局数组：";
    printArray(arr3, 3);

    // static数组和全局数组不需要，也不能用 delete[] 释放。
    // 两者每次调用返回的都是各自同一个数组，修改内容会保留下来。
    return 0;
}
