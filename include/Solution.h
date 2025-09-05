#pragma once
#include <string>
#include <vector>
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s);
    vector<int> preorderTraversal(TreeNode* root);
    vector<int> postorderTraversal(TreeNode* root);
};