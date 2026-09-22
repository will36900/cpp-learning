#include <iostream>
using namespace std;
int main(){
    int *pArr = new int[5]{1,2,3,4,5};
    int *pNewArr = new int[4];
    for (int i = 0; i <5 ; i++){
        if (i ==2){
            continue;
        }
        if (i > 2){
        pNewArr[i - 1] = pArr[i];
        }
        else{
            pNewArr[i] = pArr[i]; //注意这里的细节，因为剔除了第三个元素，所以现在两个i不是对齐的。
        }
    }
    delete[] pArr; //回收老空间
   
    pArr = pNewArr ;//将老数组的指针移向新数组。
    for (int i = 0; i < 4 ; i++){
        cout << "新数组的元素是："<< pNewArr[i] <<endl ;

    }
    return 0;
}
