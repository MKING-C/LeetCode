#include <iostream>
#include "Solution.cpp"
int main()
{
    Solution s;
    vector<int> nums = {0,1,4,6,7,10};
    int diff = 3;
    cout << s.arithmeticTriplets(nums, diff);
    return 0;
}