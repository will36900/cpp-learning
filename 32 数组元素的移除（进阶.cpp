#include <iostream>
using namespace std;
int main(){
    int *pArr =new int[10]{1,2,3,4,5,6,7,8,9,10};
    int *pNewArr = new int[8];
    int offset = 0;
    for (int i = 0; i < 10; i++){
        if (i == 0 || i ==5)
        {
            offset++;
            continue;
        }
        pNewArr[i - offset] = pArr[i];
    }
    delete[] pArr;
    pArr = pNewArr;
    for (int i = 0; i < 8; i++){
        cout << pNewArr[i] << endl;
    }
    return 0;
}