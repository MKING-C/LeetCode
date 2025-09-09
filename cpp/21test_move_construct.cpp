#include <iostream>
using namespace std;

class Test
{
public:
    Test() : m_num(new int(100))
    {
        cout << "construct: my name is jerry" << endl;
    }

    Test(const Test& a) : m_num(new int(*a.m_num))
    {
        cout << "copy construct: my name is tom" << endl;
    }

    // 添加移动构造函数
    Test(Test&& a) : m_num(a.m_num)
    {
        a.m_num = nullptr;
        cout << "move construct: my name is sunny" << endl;
    }

    ~Test()
    {
        delete m_num;
        cout << "destruct Test class ..." << endl;
    }

    int* m_num;
};

Test getObj()
{
    Test t;
    return t;
}

int main()
{
    Test t = getObj();
    cout << "t.m_num: " << *t.m_num << endl;

    std::cout << "方法1 - 强制移动:\n";
    Test t1 = std::move(getObj()); // 强制使用移动构造函数
    
    std::cout << "\n方法2 - 先存储再移动:\n";
    Test temp = getObj(); // 这里可能被RVO优化
    Test t2 = std::move(temp); // 明确调用移动构造函数
    return 0;
};