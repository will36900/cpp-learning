#include <iostream>
using namespace std;
//一旦某个参数有默认值，后面的参数也必须有默认值：
//void func(int a, int b = 2, int c = 3);  // 正确
//void func(int a = 1, int b, int c);      // 错误
//func(10);        // a=10，b=2，c=3
//func(10, 20);    // a=10，b=20，c=3
//func(10, 20, 30);// a=10，b=20，c=30