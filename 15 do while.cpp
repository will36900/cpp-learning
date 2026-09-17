#include <iostream>
using namespace std;
// int main() {
//     // 在屏幕中输出0-9这十个数字
//     int num = 0;
//     do {
//         cout << num << endl;
//         num++;

//     }

//     while (num < 10);
//     return 0;
// }
// do while 和 while 循环的区别在于，do while 循环至少会执行一次循环体，而 while 循环在条件不满足时可能一次都不执行。
int main(){
    cout <<"用do while语句找到3位数中的所有水仙花数（1^3 + 5^3 + 3^3 = 153）"<<endl;
    // 打印所有三位数字
    int num = 100;
    do{
        int a = num / 100; // 百位
        int b = (num / 10) % 10; // 十位
        int c = num % 10; // 个位
        if (a * a * a + b * b * b + c * c * c == num) {
            cout << num << "是水仙花数" << endl;
        }
        num++;
    } while (num < 1000);

    return 0;
}