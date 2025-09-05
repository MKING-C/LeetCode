# LeetCode C++ 解题项目

这个项目包含我在LeetCode上的C++解题代码和一些C++特性测试代码。

## 项目结构

```
.
├── cpp/               # C++特性测试代码目录
├── include/           # 头文件目录
│   ├── Palindrome.h   # 回文数判断函数声明
│   ├── Solution.h     # 解题函数声明
│   └── TreeNode.h     # 二叉树节点定义
├── src/               # 源文件目录
│   ├── Palindrome.cpp # 回文数判断函数实现
│   └── Solution.cpp   # 解题函数实现
└── main.cpp           # 主程序入口，用于测试
```

## 文件说明

### 核心解题文件
- [Palindrome.h](file:///c%3A/cppcode/LeetCode/include/Palindrome.h) 和 [Palindrome.cpp](file:///c%3A/cppcode/LeetCode/src/Palindrome.cpp) - 包含回文数判断的实现
- [Solution.h](file:///c%3A/cppcode/LeetCode/include/Solution.h) 和 [Solution.cpp](file:///c%3A/cppcode/LeetCode/src/Solution.cpp) - 包含LeetCode题目的解题函数实现
- [TreeNode.h](file:///c%3A/cppcode/LeetCode/include/TreeNode.h) - 二叉树节点定义
- [main.cpp](file:///c%3A/cppcode/LeetCode/main.cpp) - 主程序，用于测试解题函数

### C++特性测试文件
- [00test_static_var.cpp](file:///c%3A/cppcode/LeetCode/cpp/00test_static_var.cpp) - 静态局部变量示例
- [01test_var.cpp](file:///c%3A/cppcode/LeetCode/cpp/01test_var.cpp) - 各种变量作用域示例
- [02test_sizeof_class.cpp](file:///c%3A/cppcode/LeetCode/cpp/02test_sizeof_class.cpp) - 类的内存布局和大小测试
- [03test_sizeof_struct.cpp](file:///c%3A/cppcode/LeetCode/cpp/03test_sizeof_struct.cpp) - 结构体内存对齐测试
- [04test_unique_ptr.cpp](file:///c%3A/cppcode/LeetCode/cpp/04test_unique_ptr.cpp) - 智能指针unique_ptr使用示例
- [05test_shared_ptr.cpp](file:///c%3A/cppcode/LeetCode/cpp/05test_shared_ptr.cpp) - 智能指针shared_ptr使用示例
- [06test_lambda.cpp](file:///c%3A/cppcode/LeetCode/cpp/06test_lambda.cpp) - Lambda表达式使用示例
- [07test_palindrome.cpp](file:///c%3A/cppcode/LeetCode/cpp/07test_palindrome.cpp) - 回文数测试
- [08test_explicit.cpp](file:///c%3A/cppcode/LeetCode/cpp/08test_explicit.cpp) - explicit关键字使用示例
- [09test_static_cast.cpp](file:///c%3A/cppcode/LeetCode/cpp/09test_static_cast.cpp) - static_cast使用示例
- [10test_staticVarAsReturn.cpp](file:///c%3A/cppcode/LeetCode/cpp/10test_staticVarAsReturn.cpp) - 静态变量作为返回值示例
- [11test_preorder.cpp](file:///c%3A/cppcode/LeetCode/cpp/11test_preorder.cpp) - 二叉树前序遍历测试
- [12test_ProxyImage.cpp](file:///c%3A/cppcode/LeetCode/cpp/12test_ProxyImage.cpp) - 代理模式示例
- [13test_Observer.cpp](file:///c%3A/cppcode/LeetCode/cpp/13test_Observer.cpp) - 观察者模式示例
- [14test_Strategy.cpp](file:///c%3A/cppcode/LeetCode/cpp/14test_Strategy.cpp) - 策略模式示例

## 当前实现

目前实现了以下LeetCode题目：

### 无重复字符的最长子串
- 题目：给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
- 实现：使用滑动窗口算法，时间复杂度O(n)

### 回文数判断
- 题目：给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
- 实现：通过反转数字进行比较

### 二叉树的前序遍历
- 题目：给你二叉树的根节点 root ，返回它节点值的前序遍历。
- 实现：使用迭代方法实现

## 如何编译和运行

```bash
g++ -o main main.cpp src/Solution.cpp src/Palindrome.cpp -Iinclude
./main
```

对于单独的测试文件，可以这样编译运行：
```bash
g++ -o test cpp/00test_static_var.cpp
./test
```

## 学习资源

这些测试文件涵盖了C++的多个重要特性：
- 静态变量的使用
- 类的内存布局
- 结构体内存对齐
- 智能指针的使用
- Lambda表达式
- explicit关键字
- static_cast类型转换
- 设计模式（代理模式、观察者模式、策略模式）
- 二叉树遍历算法