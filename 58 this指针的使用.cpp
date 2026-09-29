#include <iostream>
using namespace std;
//C++ 的语言规则。 当你写 p1.birthday()，C++ 会在调用成员函数时，让函数里的 this 指向 p1；写 p2.birthday() 时，this 就指向 p2。
class Person{
    public:
    Person(int age){
        this ->m_Age = age;//this 指针指向被调用的成员函数 所属的对象
    }
    Person& PersonAddAge(Person &p)
    {
        this->m_Age += p.m_Age;
        return *this;

    }
    int m_Age;
};
void test01(){
    Person p1(18);
    cout << "p1 的年龄为： " << p1.m_Age<< endl;
}
//返回对象本身用*this
void test02(){
    Person p1(10);
    Person p2(10);
    //链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1);
    cout << "p2  的年龄： " << p2.m_Age << endl;
}
int main(){
    test01();
    test02();
    return 0;
}
