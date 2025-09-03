#include <stdio.h>

int* getStaticVarAddress() {
    static int s_value = 10; // 静态局部变量
    printf("函数内 s_value 的地址: %p\n", (void*)&s_value);
    s_value++; // 每次调用修改值，以观察效果
    return &s_value; // 安全地返回地址
}

int main() {
    int* ptr1 = getStaticVarAddress(); // 第一次调用
    printf("main 中通过 ptr1 获取的值: %d\n", *ptr1);

    int* ptr2 = getStaticVarAddress(); // 第二次调用
    printf("main 中通过 ptr2 获取的值: %d\n", *ptr2);

    printf("ptr1 和 ptr2 指向的地址是否相同: %s\n", (ptr1 == ptr2) ? "是" : "否");

    *ptr1 = 100; // 通过指针修改静态变量的值
    printf("修改后，通过 ptr2 获取的值: %d\n", *ptr2); // 再次通过ptr2访问

    return 0;
}