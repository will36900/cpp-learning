#include <iostream>
using namespace std;
int getMax(int a, int b){
    return a > b ? a : b ;
}
bool isPositive(int n){
    if (n > 0){
       return true;
    
    }else{
        return false;
    }

}
void doubleValue(int &c){
    c = c * 2;
}
void swapNumbers(int &a1, int &b1){
    int temp = a1;
    a1 = b1;
    b1 = temp;

}


int main(){
    cout << getMax(10, 20) <<endl;  // 20
    cout << getMax(8, 3) << endl;    // 8
    cout << (isPositive(5) ? "Is positive" : "Is not positive") << endl;
    cout << (isPositive(-2) ? "Is positive" : "Is not positive") << endl;
    int number = 6;
    doubleValue(number);
    cout << number << endl;
    int x = 10;
    int y =20;
    swapNumbers(x , y);
    cout << x << endl;
    cout << y << endl;

     return 0;
}