#include <iostream>
#include <memory>

// 1. 抽象策略：折扣策略接口
class IDiscountStrategy {
public:
    virtual ~IDiscountStrategy() = default;
    virtual double applyDiscount(double originalPrice) = 0;
};

// 2. 具体策略：无折扣
class NoDiscount : public IDiscountStrategy {
public:
    double applyDiscount(double originalPrice) override {
        return originalPrice;
    }
};

// 3. 具体策略：满减策略
class FullReduction : public IDiscountStrategy {
private:
    double fullAmount;
    double reduction;
public:
    FullReduction(double full, double reduce) : fullAmount(full), reduction(reduce) {}
    double applyDiscount(double originalPrice) override {
        if (originalPrice >= fullAmount) {
            return originalPrice - reduction;
        }
        return originalPrice;
    }
};

// 4. 具体策略：百分比折扣
class PercentageDiscount : public IDiscountStrategy {
private:
    double percentage;
public:
    PercentageDiscount(double percent) : percentage(percent) {}
    double applyDiscount(double originalPrice) override {
        return originalPrice * (1 - percentage);
    }
};

// 5. 上下文：订单处理器
class OrderProcessor {
private:
    std::unique_ptr<IDiscountStrategy> strategy;
public:
    void setStrategy(std::unique_ptr<IDiscountStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }
    double calculateFinalPrice(double price) {
        if (!strategy) {
            throw std::runtime_error("Discount strategy not set!");
        }
        return strategy->applyDiscount(price);
    }
};

// 6. 客户端使用
int main() {
    OrderProcessor processor;

    processor.setStrategy(std::make_unique<NoDiscount>());
    std::cout << "Price: " << processor.calculateFinalPrice(100.0) << "\n"; // 输出 100

    processor.setStrategy(std::make_unique<FullReduction>(200, 50));
    std::cout << "Price: " << processor.calculateFinalPrice(250.0) << "\n"; // 输出 200

    processor.setStrategy(std::make_unique<PercentageDiscount>(0.2)); // 8折
    std::cout << "Price: " << processor.calculateFinalPrice(100.0) << "\n"; // 输出 80

    return 0;
}