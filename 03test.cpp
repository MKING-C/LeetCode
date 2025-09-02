#include <stdio.h>
#include <stddef.h> 
// 示例结构体
struct Example {
    char a;         // 1字节
    double d; 
    int b;          // 4字节
    short c;        // 2字节
        double e;   // 8字节 (在32位系统上也可能要求8字节对齐)
};

int main() {
    printf("结构体大小: %zu bytes\n", sizeof(struct Example));
    printf("成员偏移: a=%zu, b=%zu, c=%zu, d=%zu\n,e=%zu\n ",
           offsetof(struct Example, a),
           offsetof(struct Example, b),
           offsetof(struct Example, c),
           offsetof(struct Example, d),
           offsetof(struct Example, e));
    return 0;
}