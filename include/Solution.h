#pragma once
#include <string>
#include <vector>

#include "TreeNode.h"
#include "ListNode.h"
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s);
    vector<int> preorderTraversal(TreeNode* root);
    vector<int> postorderTraversal(TreeNode* root);
    vector<vector<int>> threeSum(vector<int>& nums);
    bool isValid(string s);
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
    ListNode* mergeKLists(vector<ListNode*>& lists);
    int removeDuplicates(vector<int>& nums);
};