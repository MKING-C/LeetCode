#include <iostream>
using namespace std;

int&& value = 520;
class Test
{
public:
    Test()
    {
        cout << "construct: my name is jerry" << endl;
    }
    Test(const Test& a)
    {
        // 输出复制构造函数被调用的信息
        cout << "copy construct: my name is tom" << endl;
    }
};

Test getObj()
{
    return Test();
}

int main()
{
    int a1;

    int &&a2 = 520;        // ok
    // 右值引用只能用右值做初始化
    // int &&a2 = a1;        // error
    // Test& t = getObj();   // error
    Test && t = getObj();
    const Test& t1 = getObj();
    return 0;
}

