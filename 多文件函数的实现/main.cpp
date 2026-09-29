#include <iostream>
#include "my_func.h"

int main() {
    int result = add(3, 5);
    std::cout << "结果是：" << result << '\n';
    return 0;
}
//h 里面放声明，也就是函数的heading； cpp里面写实现