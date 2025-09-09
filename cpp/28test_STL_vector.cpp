#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* @brief 主函数
*
* 该函数演示了如何使用C++标准模板库中的vector容器，包括元素的插入、遍历、删除、排序等操作。
*
* @return 返回一个整型值，表示程序的退出状态。0表示成功，非0表示失败。
*/
int main()
{
    cout << "Hello World!\n";
    cout << "------------------------------\n";
    cout << "1.vector的使用!\n";
    vector <int> v;
    v = {5,2,6,4,1,3};
    v.push_back(6);
    for (int i:v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "元素数量: " << v.size() << endl; 
    cout << "容量: " << v.capacity() << endl; 
    v.pop_back();
    for (int i:v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "元素数量: " << v.size() << endl; 
    cout << "容量: " << v.capacity() << endl; 
    cout << endl;

    cout << "第1元素是：" << v[0] << endl;   

    sort(v.begin(),v.end());
    for (int i : v ){
        cout << i << " ";
    }
    return 0;


}