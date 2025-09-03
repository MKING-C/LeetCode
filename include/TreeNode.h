//  Definition for a binary tree node.
struct TreeNode {

    // 树节点结构体定义
    int val;                // 节点值
    TreeNode *left;         // 左子树指针
    TreeNode *right;        // 右子树指针
    TreeNode() : val(0), left(nullptr), right(nullptr) {}  // 构造函数
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};
