#include <iostream>
using namespace std;
int main() {
// 高级for循环的写法
int arr[] = {1,2,3,4,5};
for (int element: arr)
{
    cout << element << endl;
}
int i = 0;
while (i < sizeof(arr)/sizeof(arr[0]))
{
    cout << "while 循环取出来的内容：" << arr[i] << endl;
    i++;
}
for (int i = 0; i < sizeof(arr)/ sizeof(arr[0]); i++)
{
    cout <<"for 循环输出的内容：" << arr[i] << endl;
}
}
//  获得数组长度 sizeof(数组对象)/ sizeof（数组某个元素）