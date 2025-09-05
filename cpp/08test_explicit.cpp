class SafeFileHandle {
public:
    explicit operator bool() const { // 显式转换为bool
        return is_valid_;
    }
private:
    bool is_valid_;
};

int main() {
    SafeFileHandle handle;

    if (handle) { // 正确：在布尔上下文中允许显式转换
        // ...
    }

    // bool flag = handle; // 编译错误！禁止隐式转换
    bool flag2 = static_cast<bool>(handle); // 正确：显式转换

    return 0;
}