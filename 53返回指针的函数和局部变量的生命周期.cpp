#include <iostream>
using namespace std;
//返回指针的函数，就在函数返回值声明和函数名之间添加星号就可以了
int * add(int a , int b){
    int * sum = new int;
    //或者 static int sum;
    //sum = a + b;
    // return &sum;                  
    *sum = a + b;
    return sum;

}
int main(){
    int *result1 = add (1,2);
    cout << *result1 << endl;
    delete result1;
    return 0;
}