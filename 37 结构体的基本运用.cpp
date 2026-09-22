#include <iostream>
using namespace std;
int main(){
struct Student{
    string name;
    int age;
    double score;
};
    Student stu;
    stu.name = "xiao ming";
    stu.age = 19;
    stu.score = 100;
    cout << "姓名：" << stu.name << endl;
    cout << "年龄：" << stu.age << endl;
    cout << "成绩：" << stu.score << endl;

    return 0;
}

