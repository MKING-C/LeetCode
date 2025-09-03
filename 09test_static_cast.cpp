#include <iostream>

int main() {
    // 1. 基本数据类型转换
    double pi = 3.14159;
    int intPi = static_cast<int>(pi);
    std::cout << "double " << pi << " 转换为 int: " << intPi << std::endl;
    
    // 2. 整型提升
    char c = 'A';
    int i = static_cast<int>(c);
    std::cout << "char '" << c << "' 转换为 int: " << i << std::endl;
    
    // 3. void* 指针转换
    int value = 100;
    void* voidPtr = &value;
    int* intPtr = static_cast<int*>(voidPtr);
    std::cout << "通过 void* 指针访问值: " << *intPtr << std::endl;
    
    // 4. 枚举与整型转换
    enum Color { RED = 1, GREEN = 2, BLUE = 3 };
    Color color = RED;
    int colorValue = static_cast<int>(color);
    std::cout << "枚举值 RED 转换为 int: " << colorValue << std::endl;
    
    // 从整型转换回枚举
    int num = 2;
    Color newColor = static_cast<Color>(num);
    std::cout << "整型 2 转换为枚举: " << newColor << std::endl;
    
    return 0;
}