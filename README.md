# LeetCode C++ 解题项目

这个项目包含我在LeetCode上的C++解题代码和一些C++特性测试代码。

## 项目结构

```
.
├── include/                 # 头文件目录
│   ├── Solution.h           # 解题函数声明
│   └── Palindrome.h         # 回文数判断类声明
├── src/                     # 源文件目录
│   ├── Solution.cpp         # 解题函数实现
│   └── Palindrome.cpp       # 回文数判断实现
├── main.cpp                 # 主程序入口，用于测试
├── 07test_palindrome.cpp    # 回文数测试程序
└── [0-9]*test*.cpp          # C++特性测试文件
```

## 文件说明

### 核心解题文件
- [Solution.h](file:///c%3A/cppcode/LeetCode/include/Solution.h) 和 [Solution.cpp](file:///c%3A/cppcode/LeetCode/src/Solution.cpp) - 包含LeetCode题目的解题函数实现
- [Palindrome.h](file:///c%3A/cppcode/LeetCode/include/Palindrome.h) 和 [Palindrome.cpp](file:///c%3A/cppcode/LeetCode/src/Palindrome.cpp) - 回文数判断实现
- [main.cpp](file:///c%3A/cppcode/LeetCode/main.cpp) - 主程序，用于测试解题函数
- [07test_palindrome.cpp](file:///c%3A/cppcode/LeetCode/07test_palindrome.cpp) - 回文数测试程序

### C++特性测试文件
- [00test_static_var.cpp](file:///c%3A/cppcode/LeetCode/00test_static_var.cpp) - 静态局部变量示例
- [01test_var.cpp](file:///c%3A/cppcode/LeetCode/01test_var.cpp) - 各种变量作用域示例
- [02test_sizeof_class.cpp](file:///c%3A/cppcode/LeetCode/02test_sizeof_class.cpp) - 类的内存布局和大小测试
- [03test_sizeof_struct.cpp](file:///c%3A/cppcode/LeetCode/03test_sizeof_struct.cpp) - 结构体内存对齐测试
- [04test_unique_ptr.cpp](file:///c%3A/cppcode/LeetCode/04test_unique_ptr.cpp) - 智能指针unique_ptr使用示例
- [05test_shared_ptr.cpp](file:///c%3A/cppcode/LeetCode/05test_shared_ptr.cpp) - 智能指针shared_ptr使用示例
- [06test_lambda.cpp](file:///c%3A/cppcode/LeetCode/06test_lambda.cpp) - Lambda表达式使用示例

## 当前实现

### 无重复字符的最长子串
- 题目：给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
- 实现：使用滑动窗口算法，时间复杂度O(n)

### 回文数判断
- 题目：给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
- 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
- 优化实现：通过只反转一半数字来判断是否为回文数，时间复杂度从O(n)优化到O(n/2)
  - 只处理数字的一半，当原始数字小于或等于反转数字时停止
  - 分别处理奇数和偶数长度的情况

## 如何编译和运行

编译主程序：
```bash
g++ -o main main.cpp src/Solution.cpp
./main
```

编译回文数测试程序：
```bash
g++ -o test_palindrome 07test_palindrome.cpp src/Palindrome.cpp
./test_palindrome
```

## 学习资源

这些测试文件涵盖了C++的多个重要特性：
- 静态变量的使用
- 类的内存布局
- 结构体内存对齐
- 智能指针的使用
- Lambda表达式