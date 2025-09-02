#include <iostream>

// 空类
class EmptyClass {
    // 空类没有非静态成员变量
};
// 大小为 1 字节，用于确保不同实例有唯一地址 [1,3](@ref)

// 仅包含基本类型成员，无内存对齐优化
class UnoptimizedLayout {
public:
    char a;      // 1 字节
    int b;       // 4 字节 (通常需要 4 字节对齐)
    char c;      // 1 字节
    // 编译器可能在 a 后插入 3 字节填充，使 b 对齐到 4 字节
    // 在 c 后也可能插入填充，使整个结构大小为其最大对齐要求（这里是 int 的 4 字节）的整数倍
};
// 预计大小可能为 12 字节 (1 + 3填充 + 4 + 1 + 3填充) [1,8](@ref)

// 包含基本类型成员，但调整了顺序以优化布局（减少填充）
class OptimizedLayout {
public:
    int b;       // 4 字节
    char a;      // 1 字节
    char c;      // 1 字节
    // 编译器可能在 a 和 c 后插入 2 字节填充，使整个结构大小为其最大对齐要求（这里是 int 的 4 字节）的整数倍
};
// 预计大小可能为 8 字节 (4 + 1 + 1 + 2填充) [7,8](@ref)

// 包含静态成员变量
class WithStaticMember {
public:
    int normalVar;          // 4 字节 (非静态，每个实例独有)
    static int staticVar;   // 静态成员，不属于实例，存储在全局数据区，不占实例大小 [2,6](@ref)
    char ch;                // 1 字节
    // 静态成员 staticVar 不占用类实例的空间
};
// 预计大小：nonmalVar(4) + ch(1) + 3字节填充 = 8 字节 (假设默认 4 字节对齐)
int WithStaticMember::staticVar = 10; // 静态成员变量定义

// 包含虚函数（引入虚函数表指针 vptr）
class WithVirtualFunction {
public:
    virtual void foo() {}    // 虚函数，会使编译器为每个实例添加一个虚函数表指针 (vptr) [1,6](@ref)
    int x;                  // 4 字节
    char y;                 // 1 字节
    // 在 64 位系统上，vptr 通常占 8 字节
};
// 预计大小：vptr(8) + x(4) + y(1) + 3填充 = 16 字节 (64位系统，按8字节对齐) [2,6](@ref)

// 继承：基类
class BaseClass {
public:
    int baseData;           // 4 字节
    char baseChar;          // 1 字节
    // 可能 baseChar 后有 3 字节填充，总大小 8 字节
};
// 预计大小：8 字节 (4 + 1 + 3填充)

// 继承：派生类，公有继承 BaseClass
class DerivedClass : public BaseClass {
public:
    int derivedData;        // 4 字节
    char derivedChar;       // 1 字节
    // 派生类包含基类的所有非静态成员 [2,6](@ref)
    // 内存布局通常是基类成员在前，派生类成员在后 [6,8](@ref)
};
// 预计大小：BaseClass(8) + derivedData(4) + derivedChar(1) + 3填充 = 16 字节

// 多重继承：另一个基类
class AnotherBase {
public:
    int anotherData;        // 4 字节
    virtual void anotherFunc() {} // 虚函数，带来 vptr [3,6](@ref)
    // 在 64 位系统上，vptr 占 8 字节
};
// 预计大小：vptr(8) + anotherData(4) + 4填充（按8字节对齐） = 16 字节

// 多重继承：派生类继承自 BaseClass 和 AnotherBase
class MultiDerived : public BaseClass, public AnotherBase {
public:
    int multiData;          // 4 字节
    // 多重继承会导致派生类包含所有基类的非静态成员 [3,6](@ref)
    // 由于 AnotherBase 有虚函数，MultiDerived 会包含 AnotherBase 的 vptr
    // BaseClass 无虚函数，因此无 vptr
};
/* 预计内存布局（64位系统）：
   BaseClass 部分 (8字节: baseData(4) + baseChar(1) + 3填充)
   AnotherBase 部分 (16字节: vptr(8) + anotherData(4) + 4填充) 
   multiData(4) + 4填充（使整体对齐到8字节）
   总大小: 8 + 16 + 4 + 4 = 32 字节
*/

int main() {
    std::cout << "大小检查（以下结果可能因编译器、平台（32/64位）而异）:" << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "1. 空类: " << sizeof(EmptyClass) << " 字节" << std::endl;
    std::cout << "2. 未优化布局类 (char, int, char): " << sizeof(UnoptimizedLayout) << " 字节" << std::endl;
    std::cout << "3. 优化布局类 (int, char, char): " << sizeof(OptimizedLayout) << " 字节" << std::endl;
    std::cout << "4. 含静态成员变量的类: " << sizeof(WithStaticMember) << " 字节 (静态变量不占实例空间)" << std::endl;
    std::cout << "5. 含虚函数的类: " << sizeof(WithVirtualFunction) << " 字节 (包含 vptr 开销)" << std::endl;
    std::cout << "6. 基类: " << sizeof(BaseClass) << " 字节" << std::endl;
    std::cout << "7. 派生类 (继承自BaseClass): " << sizeof(DerivedClass) << " 字节" << std::endl;
    std::cout << "8. 另一个基类 (含虚函数): " << sizeof(AnotherBase) << " 字节" << std::endl;
    std::cout << "9. 多重继承类 (继承自BaseClass和AnotherBase): " << sizeof(MultiDerived) << " 字节" << std::endl;

    return 0;
}