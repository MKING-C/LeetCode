#include <iostream>
#include <vector>
#include <algorithm>

// 抽象观察者
class Observer {
public:
    virtual void update(float temperature, float humidity) = 0; // 更新接口
    virtual ~Observer() = default;
};

// 抽象主题
class Subject {
public:
    virtual void attach(Observer* observer) = 0; // 添加观察者
    virtual void detach(Observer* observer) = 0; // 移除观察者
    virtual void notify() = 0;                    // 通知观察者
    virtual ~Subject() = default;
};

// 具体主题：天气数据
class WeatherData : public Subject {
private:
    std::vector<Observer*> observers; // 观察者列表
    float temperature;
    float humidity;

public:
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }

    void detach(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        for (Observer* observer : observers) {
            observer->update(temperature, humidity);
        }
    }

    // 当设置新的测量数据时，通知所有观察者
    void setMeasurements(float temp, float humi) {
        temperature = temp;
        humidity = humi;
        notify();
    }
};

// 具体观察者：当前状况显示
class CurrentConditionsDisplay : public Observer {
private:
    float temperature;
    float humidity;

public:
    void update(float temp, float humi) override {
        temperature = temp;
        humidity = humi;
        display();
    }

    void display() const {
        std::cout << "Current conditions: " << temperature << "°C and " << humidity << "% humidity." << std::endl;
    }
};

// 客户端使用
int main() {
    WeatherData weatherData;                 // 具体主题
    CurrentConditionsDisplay currentDisplay; // 具体观察者

    weatherData.attach(&currentDisplay);     // 注册观察者

    // 模拟天气数据更新，观察者会自动收到通知
    weatherData.setMeasurements(25.5f, 65.0f);
    weatherData.setMeasurements(30.0f, 70.5f);

    return 0;
}