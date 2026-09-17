#include <iostream>
#include <random>
using namespace std;

int get_random_number(int min, int max) {
    random_device rd;  // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> dis(min, max); // define the range
int random_number = dis(gen);
return random_number;
}
int main() { 
    int num = get_random_number(1,10);
    int arr[10]; // Generate a random number between 1 and 100
    for (int i = 0; i < 10; i++) {
        cout << "请第" << i + 1 << "次输入数字" << endl; 
        cin >> arr[i];
    }
    int result = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == num) {
            result++;
        }
}
    cout << "用户猜对了"  << result << " 次。" << endl;
    return 0; 

}
