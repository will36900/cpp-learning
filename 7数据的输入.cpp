#include <iostream>
#include <string>
using namespace std;
//整型
int main(){
    int a = 0;
    cout <<"please value a number:"<< endl;
    cin >> a;
    cout <<"you input number is:"<< a << endl;
    // 字符串
    string str = "hello world";
    cout <<"please input a string:"<< endl;
    cin >> str;
    cout <<"you input string is:"<< str << endl;
    // boolean
    bool flag = false;
    cout <<"please input a boolean value(0 or 1):"<< endl;
    cin >> flag;
    cout <<"you input boolean value is:"<< flag << endl;
    return 0;
}