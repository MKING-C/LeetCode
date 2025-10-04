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
    string convertDateToBinary(string date);
    int runeReserve(vector<int> runes);
    string longestPalindrome(string s);
    void expand(const string& s, int l, int r, int& start, int& max_len);
    int arithmeticTriplets(vector<int>& nums, int diff);
    bool divisorGame(int n);
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration);
    int divide(int a, int b);
};