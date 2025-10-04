#include <vector>
#include <iostream>
#include "Solution.cpp"
using namespace std;
int main() {
    Solution s;
    vector<int> runes = {1, 6, 3, 4, 5};
    for (const auto& i : runes)
    {
        cout << i << " ";
        /* code */
    }
    int result = s.runeReserve(runes);
    cout << "Result: " << result << endl;

    runes.insert(runes.begin(), 8);
    for (const auto& i : runes)
    {
        cout << i << " ";
        /* code */
    }
    result = s.runeReserve(runes);
    cout << "Result: " << result << endl;

    runes.push_back(10);
    for (const auto& i : runes)
    {
        cout << i << " ";
        /* code */
    }
    result = s.runeReserve(runes);
    cout << "Result: " << result << endl;

    runes.emplace_back(9);
    for (const auto& i : runes)
    {
        cout << i << " ";
        /* code */
    }
    result = s.runeReserve(runes);
    cout << "Result: " << result << endl;

    runes[4] = 7;
    for (const auto& i : runes)
    {
        cout << i << " ";
        /* code */
    }
    
    result = s.runeReserve(runes);
    cout << "Result: " << result << endl;
    return 0;
}

