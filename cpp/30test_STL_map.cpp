#include <map>
#include <iostream>
using namespace std;
int main(){
    map<string,int> myMap;
    myMap["str1"] = 30;
    myMap["str2"] = 35;
    myMap["str3"] = 33;
    for (auto i : myMap)
    {
        /* code */
        cout << i.first <<"的年龄是：" << i.second <<endl;
    }
    myMap.insert({"str4",40});
    
    // 更加高效
    for (const auto& i : myMap)
    {
        /* code */
        cout << i.first <<"的年龄是：" << i.second <<endl;
    }

    string findName = "str1";
    auto it = myMap.find(findName);
    if (it != myMap.end())
    {
        /* code */
        cout << "姓名为：" << findName << "的员工的年龄为：" << it->second << endl; 
    }else {
        cout << "姓名为：" << findName << "的员工的年龄未找到！"  << endl; 
    }
    
    string deleteName = "str4";
    auto index = myMap.erase(deleteName);
    if(index){
        cout << "删除姓名为：" << deleteName << "的员工成功" << endl;
     }
    for (const auto& entry : myMap)
    {
        /* code */
        cout << entry.first <<"的年龄是：" << entry.second <<endl;
    }
    

    return 0;
}