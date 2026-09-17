#include <iostream>
using namespace std;
int main(){
    int a[2][3] = {
        {10,20,30},
        {40,50,60}

    };
    for (int i = 0; i <2; i++){
        for (int j = 0; j < 3; j++){
            cout << a[i][j] << " " ;
        }
        cout <<"\n";
        //a[行数][列数]
        //三维数组
    }
}