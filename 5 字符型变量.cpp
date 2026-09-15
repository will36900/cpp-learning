#include <iostream>
#include <string>
using namespace std;
int main(){
    char ch = 'a';//创建字符变量时，要用单引号；2 单引号内只能有一个字符，不能是字符串
    char ch1 = 'A';
    cout << "ch = " << ch << endl;
    cout <<int(ch) << endl;//输出字符对应的ASCII码值
    cout <<int(ch1) << endl;
    // C风格字符串
    char str[] = "hello world";//字符串数组
    cout << str << endl;
    // C++风格字符串
    string str1 = "hello world";
    cout << str1 << endl;
    return 0;
}
