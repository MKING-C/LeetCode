#include <iostream>
#include <string>
#include <memory>

// 1. 定义抽象主题接口
class Image {
public:
    virtual ~Image() = default;
    virtual void display() const = 0; // 显示图像的接口
};

// 2. 实现真实主题：RealImage
class RealImage : public Image {
public:
    explicit RealImage(const std::string& filename) : filename_(filename) {
        loadFromDisk(); // 在构造函数中模拟从磁盘加载，开销大
    }

    void display() const override {
        std::cout << "Displaying image: " << filename_ << std::endl;
    }

private:
    std::string filename_;

    void loadFromDisk() {
        std::cout << "Loading image from disk: " << filename_ << ". This operation is expensive." << std::endl;
        // 模拟耗时的加载过程...
    }
};

// 3. 实现代理：ProxyImage
class ProxyImage : public Image {
public:
    explicit ProxyImage(const std::string& filename) : filename_(filename), realImage_(nullptr) {}

    void display() const override {
        // 延迟初始化：只有在第一次调用display时才加载真实图像
        if (!realImage_) {
            realImage_ = std::make_shared<RealImage>(filename_);
        }
        realImage_->display(); // 委托给RealImage处理实际显示
    }

private:
    std::string filename_;
    mutable std::shared_ptr<RealImage> realImage_; // 使用智能指针管理资源
};

// 4. 客户端代码
int main() {
    std::cout << "Application started." << std::endl;

    // 创建代理时，昂贵的RealImage对象尚未创建
    std::unique_ptr<Image> image = std::make_unique<ProxyImage>("high_res_photo.jpg");

    std::cout << "Proxy created, but real image not loaded yet." << std::endl;

    // 第一次调用display：触发真实图像的加载和显示
    std::cout << "\nFirst display call:" << std::endl;
    image->display();

    // 第二次调用display：真实图像已存在，直接显示，无需再次加载
    std::cout << "\nSecond display call:" << std::endl;
    image->display();

    return 0;
}