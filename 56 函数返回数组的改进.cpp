#include <iostream>
using namespace std;
void plus_one_in_arr (int *arr , const int length){
    for(int i = 0; i < length; ++i){
        arr[i] = i + 1;
    }
}
int main(){
    int arr[3];
    plus_one_in_arr(arr, 3);
    for ( int i = 0 ; i < 3; ++ i){
        cout << arr[i] <<endl;
        
    }
    
    return 0;
}