o# LeetCode C++ 解题项目

这个项目包含我在LeetCode上的C++解题代码和一些C++特性测试代码。

## 项目结构

```
.
├── include/           # 头文件目录
│   └── Solution.h     # 解题函数声明
├── src/               # 源文件目录
│   └── Solution.cpp   # 解题函数实现
├── main.cpp           # 主程序入口，用于测试
└── [0-9]*.cpp         # C++特性测试文件
```

## 文件说明

### 核心解题文件
- [Solution.h](file:///c%3A/cppcode/LeetCode/include/Solution.h) 和 [Solution.cpp](file:///c%3A/cppcode/LeetCode/src/Solution.cpp) - 包含LeetCode题目的解题函数实现
- [main.cpp](file:///c%3A/cppcode/LeetCode/main.cpp) - 主程序，用于测试解题函数

### C++特性测试文件
- [00test.cpp](file:///c%3A/cppcode/LeetCode/00test.cpp) - 静态局部变量示例
- [01test.cpp](file:///c%3A/cppcode/LeetCode/01test.cpp) - 各种变量作用域示例
- [02test.cpp](file:///c%3A/cppcode/LeetCode/02test.cpp) - 类的内存布局和大小测试
- [03test.cpp](file:///c%3A/cppcode/LeetCode/03test.cpp) - 结构体内存对齐测试
- [04test.cpp](file:///c%3A/cppcode/LeetCode/04test.cpp) - 智能指针unique_ptr使用示例
- [05test.cpp](file:///c%3A/cppcode/LeetCode/05test.cpp) - 智能指针shared_ptr使用示例
- [06test.cpp](file:///c%3A/cppcode/LeetCode/06test.cpp) - Lambda表达式使用示例

## 当前实现

目前实现了以下LeetCode题目：

### 无重复字符的最长子串
- 题目：给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
- 实现：使用滑动窗口算法，时间复杂度O(n)

## 如何编译和运行

```bash
g++ -o main main.cpp src/Solution.cpp
./main
```

## 学习资源

这些测试文件涵盖了C++的多个重要特性：
- 静态变量的使用
- 类的内存布局
- 结构体内存对齐
- 智能指针的使用
- Lambda表达式