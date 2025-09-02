#include <iostream>
using namespace std;

void countCalls() {
    static int counter = 0; // 静态局部变量，只初始化一次
    counter++;
    cout << "函数已被调用 " << counter << " 次。" << endl;
}

int main() {
    countCalls(); // 输出：函数已被调用 1 次。
    countCalls(); // 输出：函数已被调用 2 次。
    countCalls(); // 输出：函数已被调用 3 次。
    return 0;
}