#include <iostream>
using namespace std;
//“&” 既可以作为取地址符，也可以起到引用的作用。
//引用就是在给变量取别名
//为什么要引用？ 引用可以让 a 和 b操作同一块儿内存
//一旦初始化引用，就不能再让它去操作另一块儿内存了
int main(){
    int a = 0;
    int &b = a;
        b =20;
    cout << a << endl;

}