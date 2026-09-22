#include <iostream>
using namespace std;
struct Student{
    string name;
    string major_code = "003032";
    int domitory_num = 1 ;
};
int main(){
     struct Student su1 = {"xiaoming" } ;
     struct Student su2;
     su2.name = "Jay Chou";
     su2.domitory_num = 3;
     cout << su2.name << endl;
     cout << su2.major_code << endl;
     cout << su2.domitory_num << endl;
     return 0;
}