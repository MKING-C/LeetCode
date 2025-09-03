#include "Solution.h"
#include <unordered_map>
#include <vector>
#include <stack>

int Solution::lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    int start = 0;

    for (int i = 0; i < s.length(); i++) {
        if (charIndexMap.find(s[i]) != charIndexMap.end()) {
            start = max(start, charIndexMap[s[i]] + 1);
        }
        charIndexMap[s[i]] = i;
        maxLength = max(maxLength, i - start + 1);
    }

    return maxLength;
}

vector<int> Solution::preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }
    
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
    
    while (!nodeStack.empty()) {
        TreeNode* current = nodeStack.top();
        nodeStack.pop();
        
        // 访问当前节点
        result.push_back(current->val);
        
        // 先压入右子节点，再压入左子节点
        // 这样左子节点会先出栈，实现前序遍历
        if (current->right != nullptr) {
            nodeStack.push(current->right);
        }
        if (current->left != nullptr) {
            nodeStack.push(current->left);
        }
    }
    
    return result;
}