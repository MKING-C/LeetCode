#include <stdio.h>

int global_var = 10;         // 全局变量
static int file_static_var = 20; // 静态全局变量（仅本文件可见）

void example_function() {
    int local_var = 30;      // 局部变量
    static int static_local_var = 40; // 静态局部变量

    printf("局部变量: %d\n", local_var);
    printf("静态局部变量: %d\n", static_local_var);

    local_var++;
    static_local_var++;
    global_var++;
    file_static_var++;
}

int main() {
    printf("=== 第一次调用函数 ===\n");
    example_function();      // 输出: 局部变量: 30, 静态局部变量: 40

    printf("\n=== 第二次调用函数 ===\n");
    example_function();      // 输出: 局部变量: 30, 静态局部变量: 41

    printf("\n=== 全局变量: %d ===\n", global_var); // 输出: 12
    printf("=== 静态全局变量: %d ===\n", file_static_var); // 输出: 22

    return 0;
}