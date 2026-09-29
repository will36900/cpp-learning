#include <iostream>
using namespace std;
class Student;
class Student{
    public:
    int id;
    string name;
    int age;
    string adr;
    int grade = 60;
    
    void say_hi(){
        cout << "My name is:" << name << " id:" << id << " age:" << age << " adr:" << adr << endl;
    }
    void hard_working(){
        cout << "Working out for a day." << endl;
        get_grade();
    }
    void up_grade(){
        if(grade > 60){
            cout <<"You have up-graded and your current point is "<< grade << endl;
        
        }else{
                cout <<"please carry on to upgrade." << endl;

            }
    }
    private:
    
    void get_grade(){
        grade += 1;
    }
    
};
int main(){
        class Student David;
        David.id = 1;
        David.name ="大卫袋";
        David.age = 18;
        David.adr = "China";
        David.say_hi(); 
        David.hard_working();
        David.up_grade();
        class Student stu{2,"Liu Kang",27,"America"};
        stu.say_hi();
        stu.up_grade();

        return 0;


        

    }

