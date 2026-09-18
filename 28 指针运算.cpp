#include <iostream>
using namespace std;
int main(){
    int num = 10;
    int *p = &num;
    cout << *p << endl;
    cout << p << endl;
    p++;//改变了指针保存的地址,同时访问*p没法得到十
    cout << p << endl;
    cout << *p << endl;
    int arr[3] = {10, 20, 30};
int* ad = arr;  // 指向 arr[0]

cout << *ad << endl;  // 10

ad++;
cout << *ad << endl;  // 20

ad++;
cout << *ad << endl;  // 30
}