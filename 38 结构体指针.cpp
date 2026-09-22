#include <iostream>
using namespace std;
struct Student
{
 string name ;
 int age;
 double score;   /* data */
};
void printStudent(const Student &stu){
    cout << "姓名：" << stu.name << endl;
    cout << "年龄：" << stu.age << endl;
    cout << "成绩：" << stu.score << endl;
}

int main(){
    Student stu = {"xiao ming", 18, 100};
    Student *p =&stu;
    //通过结构体指针访问成员，要使用箭头 ->：
    cout << p->name << endl;
    cout << p->age << endl;
    cout << p->score << endl;
    printStudent(stu);
    return 0;

   
}
