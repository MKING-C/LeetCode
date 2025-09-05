#include <iostream>
int main(){
    int x = 10;
    auto foo = [x]() mutable { x += 5; std::cout << x; }; // 输出15
    foo();
    std::cout << x; // 输出10，原始x未变

    auto foo2 = [&x]() { x += 5; std::cout << x; };
    foo2();// 也要像函数一样调用foo2(); 否则编译错误，
    // 因为foo2不是一个函数对象，而是一个lambda表达式。
    // 如果要调用它作为函数对象，需要使用()运算符。
    
    std::cout << x; // 输出15，
}