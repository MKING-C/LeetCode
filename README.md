# LeetCode C++ 解题项目

这个项目包含我在LeetCode上的C++解题代码和一些C++特性测试代码。

## 项目结构

```
.
├── cpp/               # C++特性测试代码目录
├── include/           # 头文件目录
│   ├── ListNode.h     # 链表节点定义
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
- [ListNode.h](file:///c%3A/cppcode/LeetCode/include/ListNode.h) - 链表节点定义
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
- [15test_didi.cpp](file:///c%3A/cppcode/LeetCode/cpp/15test_didi.cpp) - 滴滴笔试题：字符串编辑距离
- [16test_std_function.cpp](file:///c%3A/cppcode/LeetCode/cpp/16test_std_function.cpp) - std::function使用示例
- [17test_std_function2.cpp](file:///c%3A/cppcode/LeetCode/cpp/17test_std_function2.cpp) - std::function使用示例2
- [18test_std_bind.cpp](file:///c%3A/cppcode/LeetCode/cpp/18test_std_bind.cpp) - std::bind使用示例
- [19test_readvalue.cpp](file:///c%3A/cppcode/LeetCode/cpp/19test_readvalue.cpp) - 右值引用示例
- [20test_readvalue2.cpp](file:///c%3A/cppcode/LeetCode/cpp/20test_readvalue2.cpp) - 右值引用与移动语义示例
- [21test_move_construct.cpp](file:///c%3A/cppcode/LeetCode/cpp/21test_move_construct.cpp) - 移动构造函数示例
- [22test_shared_ptr.cpp](file:///c%3A/cppcode/LeetCode/cpp/22test_shared_ptr.cpp) - shared_ptr使用示例
- [23test_didi.cpp](file:///c%3A/cppcode/LeetCode/cpp/23test_didi.cpp) - 滴滴笔试题：数组平衡问题
- [24test_kuoHao_isvalue.cpp](file:///c%3A/cppcode/LeetCode/cpp/24test_kuoHao_isvalue.cpp) - 括号匹配问题测试
- [25test_linklist_merge.cpp](file:///c%3A/cppcode/LeetCode/cpp/25test_linklist_merge.cpp) - 合并两个有序链表测试
- [26test_mergeKLists.cpp](file:///c%3A/cppcode/LeetCode/cpp/26test_mergeKLists.cpp) - 合并K个有序链表测试
- [27test_three_sum.cpp](file:///c%3A/cppcode/LeetCode/cpp/27test_three_sum.cpp) - 三数之和问题测试
- [28test_STL_vector.cpp](file:///c%3A/cppcode/LeetCode/cpp/28test_STL_vector.cpp) - STL vector容器使用示例
- [29test_STL_list.cpp](file:///c%3A/cppcode/LeetCode/cpp/29test_STL_list.cpp) - STL list容器使用示例
- [30test_STL_map.cpp](file:///c%3A/cppcode/LeetCode/cpp/30test_STL_map.cpp) - STL map容器使用示例
- [31test_convertDateToBinary.cpp](file:///c%3A/cppcode/LeetCode/cpp/31test_convertDateToBinary.cpp) - 日期转换为二进制测试
- [32test_runeReserve.cpp](file:///c%3A/cppcode/LeetCode/cpp/32test_runeReserve.cpp) - 符文储备问题测试
- [33.test_STL.cpp](file:///c%3A/cppcode/LeetCode/cpp/33.test_STL.cpp) - STL容器综合使用示例
- [34test_push_back_vs_emplace_back.cpp](file:///c%3A/cppcode/LeetCode/cpp/34test_push_back_vs_emplace_back.cpp) - push_back与emplace_back性能对比
- [35test_copy_constructor_cost.cpp](file:///c%3A/cppcode/LeetCode/cpp/35test_copy_constructor_cost.cpp) - 拷贝构造函数性能开销测试
- [36test_longestPalindrome.cpp](file:///c%3A/cppcode/LeetCode/cpp/36test_longestPalindrome.cpp) - 最长回文子串测试
- [37test_arithmeticTriplets.cpp](file:///c%3A/cppcode/LeetCode/cpp/37test_arithmeticTriplets.cpp) - 等差三元组问题测试

## 当前实现

目前实现了以下LeetCode题目：

### 无重复字符的最长子串
- 题目：给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
- 实现：使用滑动窗口算法，时间复杂度O(n)
- 对应函数：[lengthOfLongestSubstring](file:///c%3A/cppcode/LeetCode/src/Solution.cpp#L7-L15)

### 回文数判断
- 题目：给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
- 实现：通过反转数字进行比较
- 对应类及函数：[Palindrome::isPalindrome](file:///c%3A/cppcode/LeetCode/src/Palindrome.cpp#L3-L35)

### 二叉树的前序遍历
- 题目：给你二叉树的根节点 root ，返回它节点值的前序遍历。
- 实现：使用迭代方法实现
- 对应函数：[preorderTraversal](file:///c%3A/cppcode/LeetCode/src/Solution.cpp#L155-L189)

### 二叉树的后序遍历
- 题目：给你二叉树的根节点 root ，返回它节点值的后序遍历。
- 实现：使用迭代方法实现
- 对应函数：[postorderTraversal](file:///c%3A/cppcode/LeetCode/src/Solution.cpp#L191-L231)

### 三数之和
- 题目：给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
- 实现：排序+双指针法
- 对应函数：[threeSum](file:///c%3A/cppcode/LeetCode/src/Solution.cpp#L44-L110)

### 有效的括号
- 题目：给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
- 实现：使用栈进行括号匹配
- 对应函数：[isValid](file:///c%3A/cppcode/LeetCode/src/Solution.cpp#L112-L153)

### 合并两个有序链表
- 题目：将两个升序链表合并为一个新的升序链表并返回。
- 实现：双指针法
- 对应函数：[mergeTwoLists](file:///c%3A/cppcode/LeetCode/src/Solution.cpp#L233-L276)

### 合并K个升序链表
- 题目：给你一个链表数组，每个链表都已经按升序排列。请你将所有链表合并到一个升序链表中。
- 实现：使用优先队列（最小堆）
- 对应函数：[mergeKLists](file:///c%3A/cppcode/LeetCode/src/Solution.cpp#L278-L317)

### 删除有序数组中的重复项
- 题目：给你一个非严格递增排列的数组 nums，请你原地删除重复出现的元素，使每个元素只出现一次。
- 实现：双指针法
- 对应函数：[removeDuplicates](file:///c%3A/cppcode/LeetCode/src/Solution.cpp#L319-L343)

### 将日期转换为二进制
- 题目：将给定格式的日期转换为二进制表示
- 实现：字符串处理和进制转换
- 对应函数：[convertDateToBinary](file:///c%3A/cppcode/LeetCode/src/Solution.cpp#L359-L421)

### 符文储备
- 题目：计算符文中相差为1的最大连续子序列长度
- 实现：排序后遍历计数
- 对应函数：[runeReserve](file:///c%3A/cppcode/LeetCode/src/Solution.cpp#L437-L455)

### 最长回文子串
- 题目：给你一个字符串 s，找到 s 中最长的回文子串。
- 实现：中心扩展法
- 对应函数：[longestPalindrome](file:///c%3A/cppcode/LeetCode/src/Solution.cpp#L456-L466) 和 [expand](file:///c%3A/cppcode/LeetCode/src/Solution.cpp#L467-L476)

### 等差三元组
- 题目：给定严格递增的整数数组和正整数 diff，找出满足条件的等差三元组个数
- 实现：使用set查找
- 对应函数：[arithmeticTriplets](file:///c%3A/cppcode/LeetCode/src/Solution.cpp#L478-L488)

### 除数博弈
- 题目：爱丽丝和鲍勃进行除数博弈，判断爱丽丝是否能获胜
- 实现：数学规律
- 对应函数：[divisorGame](file:///c%3A/cppcode/LeetCode/src/Solution.cpp#L489-L496)

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
- STL容器使用（vector, list, map, stack, queue, priority_queue, set等）
- 右值引用与移动语义
- std::function和std::bind