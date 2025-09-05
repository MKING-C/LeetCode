#include <memory>
#include <iostream>
// using namespace std;
void uniquePtrDemo() {
    std::unique_ptr<int> uPtr = std::make_unique<int>(33); // 分配内存
    std::cout << *uPtr << std::endl;
}
void uniquePtrDemo2() {
    std::unique_ptr<int> uPtr (new int(33)) ; // 分配内存
    std::cout << *uPtr << std::endl;
} // uPtr 离开作用域，内存自动释放[7](@ref)
void uniquePtrDemo3() {
    std::unique_ptr<int> uPtr;
    uPtr.reset(new int(33)); // 分配内存
    std::cout << *uPtr << std::endl;

}
int main() {
    uniquePtrDemo();
    uniquePtrDemo2();
    uniquePtrDemo3();
    return 0;
}