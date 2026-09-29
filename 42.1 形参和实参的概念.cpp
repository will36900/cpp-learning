#include <iostream>
using namespace std;

void printSum(int x, int y) {  // x、y 是形参
    cout << x + y << '\n';
}

int main() {
    int a = 3;
    int b = 5;

    printSum(a, b);  // a、b 是实参
}