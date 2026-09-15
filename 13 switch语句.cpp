#include <iostream>
using namespace std;
int main() {
cout <<"请输入这部电影的分数（0-10）。" << endl;
int score;
cin >> score;
cout << "你输入的分数是：" << score << endl;
switch (score) {
case 10:
case 9: 
case 8:
case 7:
    cout << "太棒了！" << endl;
    break;
case 6:
case 5:
    cout << "还行吧。" << endl;
    break;
case 4:
case 3:
case 2:
case 1:
case 0:
    cout << "不太好看。" << endl;
    break;
default:
    cout << "输入的分数不在范围内，请输入0-10之间的分数。" << endl;
    break;
}
}
// switch的case不能放区间，只能放常量，但是效率比if-else高。