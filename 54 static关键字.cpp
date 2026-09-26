#include <iostream>
using namespace std;
int * add(int a, int b){
    static int sum;
    sum = a + b;
    return &sum;

}
int main(){
    int *result = add(1 , 2);
    cout << *result << endl;
    return 0;

}