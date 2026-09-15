#define Day 7
#include <iostream>
using namespace std;

int  main(){
    // Day = 14;// 试图修改常量变量的值，编译器会报错
    cout <<"there are "<< Day <<" days in a week"<<endl;
const int month = 12;
    cout <<"there are "<< month <<" months in a year"<<endl;
//const 修饰的变量是常量变量，不能被修改。


    int a = 10;
    int b = 20;
    int c = a + b;
    cout << "c = " << c << endl;
    return 0;
}
// 标识符命名规则：下划线，字母，数字组成，不能以数字开头，不能使用关键字，区分大小写。只能用下划线和字母开头。