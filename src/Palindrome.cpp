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
    
    // 末尾为0的数不是回文数（除了0本身）
    if (x % 10 == 0) {
        return false;
    }
    
    int reversed = 0;
    
    // 只反转一半数字
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    
    // 当数字长度为奇数时，需要去掉反转后的数字的最后一位
    return x == reversed || x == reversed / 10;
}