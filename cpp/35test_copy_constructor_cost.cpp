#include <iostream>
#include <vector>
#include <string>
#include <chrono>

class HeavyObject {
private:
    std::string data;
    int* large_array;
    static int copy_count;
    static int construct_count;

public:
    // 构造函数
    HeavyObject(const std::string& str) : data(str) {
        // 模拟分配大量内存
        large_array = new int[10000];
        for (int i = 0; i < 10000; ++i) {
            large_array[i] = i;
        }
        construct_count++;
        std::cout << "构造函数被调用，对象编号: " << construct_count << std::endl;
    }

    // 拷贝构造函数
    HeavyObject(const HeavyObject& other) : data(other.data) {
        // 模拟拷贝大量数据
        large_array = new int[10000];
        for (int i = 0; i < 10000; ++i) {
            large_array[i] = other.large_array[i];
        }
        copy_count++;
        std::cout << "拷贝构造函数被调用，拷贝次数: " << copy_count << std::endl;
    }

    // 移动构造函数 (C++11)
    HeavyObject(HeavyObject&& other) noexcept : data(std::move(other.data)), large_array(other.large_array) {
        other.large_array = nullptr;
        std::cout << "移动构造函数被调用" << std::endl;
    }

    // 析构函数
    ~HeavyObject() {
        delete[] large_array;
    }

    static void reset_counters() {
        copy_count = 0;
        construct_count = 0;
    }

    static int get_copy_count() { return copy_count; }
    static int get_construct_count() { return construct_count; }
};

int HeavyObject::copy_count = 0;
int HeavyObject::construct_count = 0;

int main() {
    std::cout << "=== 比较push_back和emplace_back的性能 ===" << std::endl;
    
    // 测试push_back的性能
    HeavyObject::reset_counters();
    auto start = std::chrono::high_resolution_clock::now();
    
    std::vector<HeavyObject> vec1;
    for (int i = 0; i < 5; ++i) {
        HeavyObject obj("test_data_" + std::to_string(i));
        vec1.push_back(obj);  // 会调用拷贝构造函数
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "push_back - 构造次数: " << HeavyObject::get_construct_count() 
              << ", 拷贝次数: " << HeavyObject::get_copy_count() 
              << ", 耗时: " << duration1.count() << " 微秒" << std::endl << std::endl;

    // 测试emplace_back的性能
    HeavyObject::reset_counters();
    start = std::chrono::high_resolution_clock::now();
    
    std::vector<HeavyObject> vec2;
    for (int i = 0; i < 5; ++i) {
        vec2.emplace_back("test_data_" + std::to_string(i));  // 直接构造，无拷贝
    }
    
    end = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "emplace_back - 构造次数: " << HeavyObject::get_construct_count() 
              << ", 拷贝次数: " << HeavyObject::get_copy_count() 
              << ", 耗时: " << duration2.count() << " 微秒" << std::endl << std::endl;

    std::cout << "性能提升: " << (duration1.count() > duration2.count() ? 
               (double)duration1.count() / duration2.count() : 
               (double)duration2.count() / duration1.count()) << "倍" << std::endl;

    return 0;
}