#include <iostream>
using namespace std;
int main(){
    int *pArr = new int[10]{1,3,6,7,4,2,5,8,9,10};
    int min; 
    int min_index;
    for(int i = 0; i < 9; i++){
        for (int j = i , j < 10; j++){
            if (j == i){
                min = pArr[j];
                min_index = j;
            }
            if (pArr[j] < min){
                min = pArr[j];
                min_index = j;
            }
        }
        int tmp = pArr[i]; //临时变量进行备份 temp
        pArr[i] = pArr[min_index];
        pArr[min_index] = temp;
    }
    for (int i = 0; i < 0; i++)
    {
        cout << pArr[i] << "," << ;
    }
    return 0,

}