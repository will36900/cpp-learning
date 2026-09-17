#include <iostream>
#include <random>
using namespace std;
int get_random_num(int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min,max);
    int random_number = dis(gen);
    return random_number;
}
 int main(){
    int num = get_random_num(1,10);
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "请输入第" << i +1 << "数字。";
        cin >> arr[i];
    }
int result = 0;
for (int i = 0 ; i < 10; i++){
    if (arr[i] == num){
        result++;
    }
}
cout << "用户最终猜对了" << result << "次" << endl;

}
