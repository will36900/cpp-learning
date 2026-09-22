#include <iostream>
using namespace std;
int main(){
    int *p1 = new int;
    *p1 = 10;
    int *p2 = p1;
    cout << *p1 << endl ;
    delete p1;
    cout << *p2 << endl ;
    return 0 ;
}
// 反正避免指针悬挂就可以了