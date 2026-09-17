#include<iostream>
#include<ctime>

using namespace std;
int main(){
    // int sum = 0;
    // while(sum < 100){
    //     sum += 10;
    //     cout << "sum = " << sum << endl;
    // }
    // return 0;
    // 猜数字游戏
    //生成1-100之间的随机数
    srand(time(0));
    int num = rand() % 100 + 1;
    int guess;
    cout << "猜数字游戏开始，请输入你猜的数字（1-100）：" << endl;
    while (true) {
        cin >> guess;
        if (guess < 1 || guess > 100) {
            cout << "输入的数字不在范围内，请输入1-100之间的数字。" << endl;
            continue;
        }
        if (guess < num) {
            cout << "你猜的数字太小了，请再试一次：" << endl;
        } else if (guess > num) {
            cout << "你猜的数字太大了，请再试一次：" << endl;
        } else {
            cout << "恭喜你，猜对了！" << endl;
            break;
        }
    }
    return 0;
}
// 如果希望每次打开游戏时答案能变化，就加上时间种子。
// srand(time(0));