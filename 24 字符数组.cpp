#include <iostream>
using namespace std;
int main(){
    char s[] = "hello" ;
    cout << s[0] << endl;
    cout << s[1] << endl;
    cout << s[2] << endl;
    cout << s[3] << endl;
    cout << s[4] << endl;
    cout << s[5] << endl;
    cout << sizeof(s) << endl;
    for (char i: s)
    {
        cout << i ;
    }
    return 0;
}
// char s[] = "hello"== char s[] = {'h', 'e', 'l', 'l', 'o', '\0'};
// 中文要用string类型。