#include <memory>
#include <iostream>
// using namespace std;
void uniquePtrDemo() {
    std::shared_ptr<int> uPtr = std::make_unique<int>(33); // 分配内存
    std::cout << *uPtr << std::endl;
}
void uniquePtrDemo2() {
    std::shared_ptr<int> uPtr (new int(33)) ; // 分配内存
    std::cout << *uPtr << std::endl;
    {
        std::shared_ptr<int> uPtr2 = uPtr;
        std::cout << "1 use_count的值为：" << uPtr.use_count()<<std::endl;
    }
    std::cout << "2 use_count的值为："<< uPtr.use_count()<<std::endl;
    uPtr.reset(); // 释放内存
    std::cout << "3 use_count的值为："<< uPtr.use_count()<<std::endl;
    std::cout << *uPtr << std::endl;
    if (uPtr == nullptr)
    {
        std::cout << "uPtr是空指针" << std::endl;
    }
    
    int *p = uPtr.get();
    std::cout << *p << std::endl;
} // uPtr 离开作用域，内存自动释放[7](@ref)
void uniquePtrDemo3() {
    std::shared_ptr<int> uPtr;
    uPtr.reset(new int(33)); // 分配内存
    std::cout << *uPtr << std::endl;

}
int main() {
    uniquePtrDemo();
    uniquePtrDemo2();
    uniquePtrDemo3();
    return 0;
}