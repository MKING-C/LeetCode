# include <iostream>
# include <string>
# include "Solution.cpp"
using namespace std;

int main() {
    Solution solution;
    string input = "";
    cout << "Enter a string: ";
    getline(cin, input);
    int length = solution.lengthOfLongestSubstring(input);
    cout << "Length of longest substring without repeating characters: " << length << endl;
    return 0;
}
