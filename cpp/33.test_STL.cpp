#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
struct Person {
    std::string name;
    int age;

    // 重载 < 运算符，用于比较
    bool operator<(const Person& other) const {
        return age < other.age; // 按年龄升序排序
    }
};

using namespace std;
int main(){
    cout<<"--------------vector--------------";
    vector<int> vec1{1,2};
    for(auto i:vec1){
        cout<<i<<' ';
    }
    cout<<"\n";
    // 创建并初始化一个包含 5 个元素的 vector，初始值为 0
    vector<int> vec2(5);
    for(auto i:vec2){
        cout<<i<<' ';
    }
    cout<<"\n";
    // 创建并初始化一个包含 5 个元素的 vector，初始值为 10
    vector<int> vec3(5, 10);
    for (auto it = vec3.begin(); it != vec3.end(); it++)
    {
        cout<<*it <<' ';
    }
    cout<<"\n";
    vec1.push_back(40);
    vec1.emplace_back(35);
    vec1.emplace_back(25);
    for (size_t i = 0; i < vec1.size(); i++)
    {
        /* code */
        cout<< vec1[i] << " ";
    }
    cout<<"\n";
    sort(vec1.begin(),vec1.end());
    for (size_t i = 0; i < vec1.size(); i++)
    {
        /* code */
        cout<< vec1[i] << " ";
    }
    cout<<"\n";
    cout<<"--------------list--------------";
    list<float> floatList1;
    list<float> floatList2(10);

    for(auto it = floatList1.begin();it != floatList1.end();it++){
        cout << "*it "<<" ";
    }
    cout<<"\n";

    for(auto it = floatList2.begin();it != floatList2.end();it++){
        cout << *it <<" ";
    }

    cout<<"\n";
    // 在头部添加元素
    floatList2.push_front(11);
    cout<<"在头部添加元素：";
    for(auto it = floatList2.begin();it != floatList2.end();it++){
        cout << *it <<" ";
    }
    cout<<"\n";

    floatList2.push_back(22);
    cout<<"在尾部添加元素：";
    for(auto it = floatList2.begin();it != floatList2.end();it++){
        cout << *it <<" ";
    }
    cout<<"\n";
    // 删除头部元素
    floatList2.pop_front();
    cout<<"删除头部元素：";
    for(auto it = floatList2.begin();it != floatList2.end();it++){
        cout << *it <<" ";
    }
    cout<<"\n";
    // 删除尾部元素
    floatList2.pop_back();
    cout<<"删除尾部元素：";
    for(auto it = floatList2.begin();it != floatList2.end();it++){
        cout << *it <<" ";
    }
    cout<<"\n";

    list<float> floatList3{1.2,3.5,6.6,8.5,3.4,6.7,9.9,6.6};
    for(auto it = floatList3.begin();it != floatList3.end();it++){
        cout << *it <<" ";
    }
    cout<<"\n";
    floatList3.sort();
        cout<<"排序后：";
    for(auto it = floatList3.begin();it != floatList3.end();it++){
        cout << *it <<" ";
    }
    cout<<"\n";
    floatList3.unique();
    cout<<"去重后：";
    for(auto it = floatList3.begin();it != floatList3.end();it++){
        cout << *it <<" ";
    }
    cout<<"\n";

    floatList3.merge(floatList2);
        cout<<"去重后：";
    for(auto it = floatList3.begin();it != floatList3.end();it++){
        cout << *it <<" ";
    }
    cout<<"\n";
    cout<<"--------------stack--------------"<<endl;
    stack<float> floatStack;
    floatStack.push(1.2);
    floatStack.push(3.5);
    floatStack.push(6.6);
    floatStack.push(8.5);
    floatStack.push(3.4);
    floatStack.push(6.7);
    floatStack.push(9.9);
    floatStack.push(6.6);
    cout<<"栈顶元素："<<floatStack.top()<<endl;

    while(!floatStack.empty()){
        cout<<floatStack.top();
        floatStack.pop();
    }

    cout<<endl;
    // 使用 vector 作为底层容器
    std::stack<int, std::vector<int>> stack;
    // 添加元素
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // 输出 stack 的内容
    std::cout << "Stack: ";
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    cout<<endl;
    cout<<"--------------deque--------------"<<endl;
    deque<int> deque1;
    deque1.push_back(10);
    deque1.push_back(20);
    deque1.push_back(30);
    deque1.push_front(5);
    deque1.push_front(1);
    cout<<"deque1: ";
    for(auto i:deque1){
        cout<<i<<' ';
    }
    cout<<"\n";
    for (auto it = deque1.begin(); it != deque1.end(); it++)
    {
        cout<< *it <<" "; 
    }
        cout<<"\n";
    cout<<"--------------queue--------------"<<endl;
    // 创建一个空的 priority_queue（默认是最大堆）
    priority_queue<int> pq;
    // 向队列中添加元素
    pq.push(16);
    pq.push(20);
    pq.push(15);
    pq.push(12);
    pq.push(25);
    cout<<"优先级队列中的元素：";
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    // 使用 vector 初始化 priority_queue
    std::vector<int> vec = {3, 1, 4, 1, 5, 9};
    std::priority_queue<int> pq2(vec.begin(), vec.end());
    cout<<"优先级队列中的元素：";
    while(!pq2.empty()){
        cout<<pq2.top()<<" ";
        pq2.pop();
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq3(vec.begin(), vec.end());
    cout<<"队列中的元素：";
    while(!pq3.empty()){
        cout<<pq3.top()<<" ";
        pq3.pop();
    }
    cout<<endl;
    cout<<"--------------set--------------"<<endl;
    set<int> s1;
    s1.insert(1);
    s1.insert(4);
    s1.insert(3);
    s1.insert(6);
    s1.insert(5);
    s1.insert(6);
    for(auto i:s1){
        cout<<i<<' ';
    }
    cout<<endl;

    std::set<Person> set;
    // 添加元素
    set.insert({"Alice", 30});
    set.insert({"Bob", 20});
    set.insert({"Charlie", 25});

    // 输出 set 的内容
    std::cout << "People sorted by age:\n";
    for (const auto& person : set) {
        std::cout << person.name << " (" << person.age << ")\n";
    }
    return 0;
}
