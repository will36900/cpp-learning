#include<iostream>
using namespace std;
int main(){
    // 三目运算符的使用
    int a = 10, b = 20;
    int max = (a > b) ? a : b;//if (a > b) max = a; else max = b;
    cout << "较大的数是: " << max << endl;
    return 0;
}