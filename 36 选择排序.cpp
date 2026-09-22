#include <iostream>
using namespace std;

int main() {
    int *pArr = new int[10]{1, 3, 6, 7, 4, 2, 5, 8, 9, 10};

    int min;        // 记录最小值，用于比较
    int min_index;  // 记录最小值所在的下标

    // 外层循环：一共进行9轮
    for (int i = 0; i < 9; i++) {
        // 内层循环：在未排序的范围中寻找最小值
        for (int j = i; j < 10; j++) {
            // 先把未排序区域的第一个元素当作最小值
            if (j == i) {
                min = pArr[j];
                min_index = j;
            }

            // 如果找到更小的值，就更新最小值和它的下标
            if (pArr[j] < min) {
                min = pArr[j];
                min_index = j;
            }
        }

        // 把本轮找到的最小值与第i个元素交换
        int temp = pArr[i];
        pArr[i] = pArr[min_index];
        pArr[min_index] = temp;
    }

    for (int i = 0; i < 10; i++) {
        cout << pArr[i];
        if (i < 9) {
            cout << ",";
        }
    }
    cout << endl;

    delete[] pArr;
    pArr = nullptr;

    return 0;
}
