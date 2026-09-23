#include <iostream>
using namespace std;
void func(int arr[], int length){ 
    //最推荐就是这个命名方式
    for (int i = 0; i < length; i++){
        cout << arr[i] << endl;
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    func(arr, 9);
    return 0;
}
