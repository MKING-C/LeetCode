#include <iostream>
#include "Palindrome.cpp"

int main() {
    Palindrome p;
    
    // 测试用例
    int testCases[] = {121, -121, 10, 0, 1221, 12321, 123,4444};
    int size = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < size; i++) {
        int num = testCases[i];
        bool result = p.isPalindrome(num);
        std::cout << "数字 " << num << " 是回文数吗? " << (result ? "是" : "否") << std::endl;
    }
    
    return 0;
}