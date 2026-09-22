#include <iostream>
using namespace std;
int main(){
int a = 10, b = 20;

// 左定值：值不能改，指向能改
const int* p1 = &a;
// *p1 = 100;  // ❌
p1 = &b;       // ✅

// 右定向：值能改，指向不能改
int* const p2 = &a;
*p2 = 100;     // ✅
// p2 = &b;    // ❌

// 两边 const：都不能改
const int* const p3 = &a;
// *p3 = 100;  // ❌
// p3 = &b;    // ❌
}