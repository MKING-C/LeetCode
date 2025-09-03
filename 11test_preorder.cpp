#include <iostream>
#include <vector>
#include "Solution.cpp"
int main() {
    // 构建测试二叉树: [1,2,3,4,5,null,8,null,null,6,7,9]
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   8
    //      / \ /
    //     6  7 9
    
    TreeNode* root = new TreeNode();
    Solution solution;
    std::vector<int> result = solution.preorderTraversal(root);
        std::cout << "前序遍历结果: ";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    // 构建测试二叉树: [1,2,3,4,5,null,8,null,null,6,7,9]
    root->val = 1;
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
    

    std::vector<int> result2 = solution.preorderTraversal(root);
    
    std::cout << "前序遍历结果: ";
    for (int i = 0; i < result2.size(); i++) {
        std::cout << result2[i];
        if (i < result2.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    
    // 释放内存
    // 注意：这里为了简化没有完全释放所有节点的内存
    
    return 0;
}