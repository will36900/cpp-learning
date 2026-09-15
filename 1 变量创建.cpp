
// 创建变量的语法：数据类型 变量名 = 变量初始值;
#include <iostream>
using namespace std;

int main() {
    int age = 0 ; 
    cout << "请输入一个年龄 "<<endl;// 创建一个名为age的整型变量，并初始化为25
    cin >> age;
    cout << "age: " << age << endl; // 输出变量age的值

    if (age >= 30)
    {
        cout << "You are an old fat ass." << endl ;
    }
    else
    {
        cout << "Too young too naive." << endl ;
    }
    return 0;
}
