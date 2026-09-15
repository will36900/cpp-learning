#include<iostream>
using namespace std;
int main(){
int dividend = 10;
int divisor = 2;
cout << dividend / divisor << endl;
// %取模
int remainder = 10 % 3;
cout << remainder << endl;
// 两个小数是不能进行取模运算的
// 前置递增
int preIncrementA = 10;
int preIncrementB = ++preIncrementA; // a先加1，再赋值给b
cout << "a = " << preIncrementA << endl; // a = 11
cout << "b = " << preIncrementB << endl; // b = 11
// 后置递增. 先进行表达式运算，后让变量+1
int postIncrementA = 10;
int postIncrementB = postIncrementA++; // b先赋值为a的值，再a加1
cout << "a = " << postIncrementA << endl; // a = 11
cout << "b = " << postIncrementB << endl; // b = 10
// 前置递减
int preDecrementA = 10;
int preDecrementB = --preDecrementA; // a先减1，再赋值给b
cout << "a = " << preDecrementA << endl; // a = 9
cout << "b = " << preDecrementB << endl; // b = 9
// 后置递减
int postDecrementA = 10;
int postDecrementB = postDecrementA--; // b先赋值为a的值，再a减1
cout << "a = " << postDecrementA << endl; // a = 9
cout << "b = " << postDecrementB << endl; // b = 10

// 赋值运算符 += -= *= /= %=
int assignA = 10;
assignA += 5; // 等价于 a = a + 5
cout << "a = " << assignA << endl; // a = 15
int assignB = 10;
assignB -= 5; // 等价于 b = b - 5
cout << "b = " << assignB << endl; // b = 5
int assignC = 10;
assignC *= 5; // 等价于 c = c * 5
cout << "c = " << assignC << endl; // c = 50
int assignD = 10;
assignD /= 5; // 等价于 d = d / 5
cout << "d = " << assignD << endl; // d = 2
int assignE = 10;
assignE %= 3; // 等价于 e = e % 3
// 比较运算符  == != <=
int compareA = 10;
int compareB = 20;
cout << (compareA == compareB) << endl;
}
// 逻辑运算符 ! &&(and) ||(or )
