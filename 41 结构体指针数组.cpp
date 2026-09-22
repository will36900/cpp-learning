#include <iostream>
using namespace std;
struct Student {
    string name;
    int age;
};

Student stu1 = {"小明", 18};
Student stu2 = {"小红", 19};
Student stu3 = {"小刚", 20};
int main(){
Student *stud[3] ={&stu1, &stu2, &stu3}; 
for (int i = 0; i < 3; i++){
     cout << stud[i]->name << endl;
     cout << stud[i]->age << endl;
   
}
return 0;
}