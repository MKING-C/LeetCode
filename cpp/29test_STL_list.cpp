#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    // 创建一个list，并初始化
    list<int> l1 = {1,2,3,4,5};
    cout << "list l1: ";
    for(auto i : l1){
        cout << i << " ";
    }
    cout << endl;

    l1.push_back(6);
    cout << "list l1: ";
    for(auto i : l1){
        cout << i << " ";
    }
    cout << endl;
    l1.push_front(7);
    cout << "list l1: ";
    for(auto i : l1){
        cout << i << " ";
    }
    cout << endl;

    // sort(l1.begin(),l1.end());
    cout << "list l1: ";
    for (int i:l1){
        cout << i <<" ";
    }
    cout << "list 不能用sort进行排序，能用的只有vector和deque两种 "<< endl;
    l1.remove(1);
    cout << "list l1: ";
    for(auto i : l1){
        cout << i << " ";
    }
    cout << endl;


    return 0;
}