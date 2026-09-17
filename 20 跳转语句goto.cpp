#include <iostream>
using namespace std;
int main() {
    goto label;
    cout << "这行代码不会被执行" << endl;
label:
    cout << "这行代码会被执行" << endl;
    return 0;
}