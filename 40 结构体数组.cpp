#include <iostream>
using namespace std;
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    double score;
};

int main() {
    Student students[3] = {
        {"小明", 18, 95.5},
        {"小红", 17, 98},
        {"小刚", 19, 88.5}
    };

    for (int i = 0; i < 3; i++) {
        cout << "第" << i + 1 << "个学生" << endl;
        cout << "姓名：" << students[i].name << endl;
        cout << "年龄：" << students[i].age << endl;
        cout << "成绩：" << students[i].score << endl;
        cout << endl;
    }

    return 0;
}