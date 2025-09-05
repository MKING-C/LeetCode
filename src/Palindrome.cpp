#include "Palindrome.h"

bool Palindrome::isPalindrome(int x) {
    // 负数不是回文数
    if (x < 0) {
        return false;
    }
    
    // 0是回文数
    if (x == 0) {
        return true;
    }
    
    // 个位数都是回文数
    if (x < 10) {
        return true;
    }
    
    // 末尾为0的数不是回文数（除了0本身）
    if (x % 10 == 0) {
        return false;
    }
    
    long long reversed = 0;
    int original = x;
    
    // 反转数字
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    
    // 比较原数字和反转后的数字
    return original == reversed;
}