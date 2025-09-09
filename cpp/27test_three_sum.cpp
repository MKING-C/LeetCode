#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution solution;
    
    // 测试用例1: [-1,0,1,2,-1,-4]
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    cout << "测试用例1: [-1,0,1,2,-1,-4]" << endl;
    vector<vector<int>> result1 = solution.threeSum(nums1);
        cout << "执行过后:" << endl;
    for (const auto& num:nums1) {
        cout << num << " ";
    }
    cout << endl;
    cout << "结果:" << endl;
    for (const auto& triplet : result1) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    cout << endl;
    
    // 测试用例2: [0,1,1]
    vector<int> nums2 = {0, 1, 1};
    cout << "测试用例2: [0,1,1]" << endl;
    vector<vector<int>> result2 = solution.threeSum(nums2);
    cout << "结果:" << endl;
    if (result2.empty()) {
        cout << "[]" << endl;
    } else {
        for (const auto& triplet : result2) {
            cout << "[";
            for (int i = 0; i < triplet.size(); i++) {
                cout << triplet[i];
                if (i < triplet.size() - 1) cout << ",";
            }
            cout << "]" << endl;
        }
    }
    cout << endl;
    
    // 测试用例3: [0,0,0]
    vector<int> nums3 = {0, 0, 0};
    cout << "测试用例3: [0,0,0]" << endl;
    vector<vector<int>> result3 = solution.threeSum(nums3);
    cout << "执行过后:" << endl;
    for (const auto& num:nums3) {
        cout << num << " ";
    }
    cout << endl;
    cout << "结果:" << endl;
    for (const auto& triplet : result3) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    cout << endl;
    
    // 测试用例4: 空数组
    vector<int> nums4 = {};
    cout << "测试用例4: []" << endl;
    vector<vector<int>> result4 = solution.threeSum(nums4);
    cout << "结果:" << endl;
    if (result4.empty()) {
        cout << "[]" << endl;
    }
    cout << endl;
    
    // 测试用例5: [1,2,-2,-1]
    vector<int> nums5 = {1, 2, -2, -1};
    cout << "测试用例5: [1,2,-2,-1]" << endl;
    vector<vector<int>> result5 = solution.threeSum(nums5);
    cout << "结果:" << endl;
    if (result5.empty()) {
        cout << "[]" << endl;
    } else {
        for (const auto& triplet : result5) {
            cout << "[";
            for (int i = 0; i < triplet.size(); i++) {
                cout << triplet[i];
                if (i < triplet.size() - 1) cout << ",";
            }
            cout << "]" << endl;
        }
    }
    
    return 0;
}