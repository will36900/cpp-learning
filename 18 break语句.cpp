#include <iostream>
using namespace std;
int main(){
    int select ;
    cout << "1 简单 " << endl;
    cout << "2 一般 " << endl;
    cout << "3 困难 " << endl;
    cout << "请选择难度：";
    cin >> select;
    switch (select) {
        case 1:
            cout << "你选择了简单难度" << endl;
            break;
        case 2: 
            cout << "你选择了一般难度" << endl;
            break;
        case 3:
            cout << "你选择了困难难度" << endl;
            break;
        default:
            cout << "你选择的难度不存在" << endl;
    }
    return 0;
}