#include <iostream>
#include <vector>
#include <string>

class Person {
public:
    std::string name;
    int age;

    // 构造函数
    Person(const std::string& n, int a) : name(n), age(a) {
        std::cout << "Person构造函数被调用: " << name << ", " << age << std::endl;
    }

    // 拷贝构造函数
    Person(const Person& other) : name(other.name), age(other.age) {
        std::cout << "Person拷贝构造函数被调用: " << name << ", " << age << std::endl;
    }
};

int main() {
    std::cout << "使用push_back添加对象:" << std::endl;
    std::vector<Person> peopleList;
    Person p1("Alice", 25);
    peopleList.push_back(p1);  // 会调用拷贝构造函数

    std::cout << "\n使用push_back添加临时对象:" << std::endl;
    std::vector<Person> people2;
    people2.push_back(Person("Bob", 30));  // 先构造临时对象，再调用拷贝构造函数

    std::cout << "\n使用emplace_back直接构造对象:" << std::endl;
    std::vector<Person> people3;
    people3.emplace_back("Charlie", 35);  // 直接在vector中构造对象，无需拷贝

    std::cout << "\n基本类型int的比较:" << std::endl;
    std::vector<int> numbers1;
    numbers1.push_back(42);  // 对于基本类型，两者几乎没有区别

    std::vector<int> numbers2;
    numbers2.emplace_back(42);

    return 0;
}