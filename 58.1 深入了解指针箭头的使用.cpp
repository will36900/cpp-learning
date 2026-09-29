#include <iostream>
using namespace std;

class Person {
public:
    int age;

    void show() {
        cout << "this 的值：" << this << '\n';
        cout << "this->age：" << this->age << '\n';
    }
};

int main() {
    Person p1{10};
    Person p2{20};

    cout << "p1 的地址：" << &p1 << '\n';
    p1.show();

    cout << "p2 的地址：" << &p2 << '\n';
    p2.show();
}