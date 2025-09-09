#include "Solution.h"
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <queue>
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

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
    //题目：
    /*
    给你一个整数数组 nums ，
    判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
    同时还满足 nums[i] + nums[j] + nums[k] == 0 。
    请你返回所有和为 0 且不重复的三元组。

    注意：答案中不可以包含重复的三元组。

    示例 1：
    输入：nums = [-1,0,1,2,-1,-4]
    输出：[[-1,-1,2],[-1,0,1]]
    解释：
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
    不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
    注意，输出的顺序和三元组的顺序并不重要。
    示例 2：
    输入：nums = [0,1,1]
    输出：[]
    解释：唯一可能的三元组和不为 0 。
    示例 3：
    输入：nums = [0,0,0]
    输出：[[0,0,0]]
    解释：唯一可能的三元组和为 0 。
    提示：
    3 <= nums.length <= 3000
    -105 <= nums[i] <= 105
    */

    //代码
    // 创建了一个二维动态数组，用于存储多个整数向量
    vector<vector<int>> result;
    
    // 如果数组长度小于3，无法组成三元组
    if (nums.size() < 3) {
        return result;
    }
    
    // 先对数组进行排序
    sort(nums.begin(), nums.end());
    
    // 遍历数组，固定第一个数
    for (int i = 0; i < nums.size() - 2; i++) {
        // 如果当前数字大于0，由于数组已排序，后面的数字都大于0，三数之和不可能为0
        if (nums[i] > 0) {
            break;
        }
        
        // 跳过重复元素，避免出现重复三元组
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        // 使用双指针寻找另外两个数
        int left = i + 1;
        int right = nums.size() - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                // 找到一个三元组
                result.push_back({nums[i], nums[left], nums[right]});
                
                // 跳过重复元素
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                
                // 移动指针继续寻找
                left++;
                right--;
            } else if (sum < 0) {
                // 和小于0，需要增大，移动左指针
                left++;
            } else {
                // 和大于0，需要减小，移动右指针
                right--;
            }
        }
    }
    
    return result;
}

bool Solution::isValid(string s) {
    /*
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，
    判断字符串是否有效。
    有效字符串需满足：
        左括号必须用相同类型的右括号闭合。
        左括号必须以正确的顺序闭合。
        每个右括号都有一个对应的相同类型的左括号。
    */
   
    // 使用栈来解决括号匹配问题
    stack<char> st;
    
    // 遍历字符串中的每个字符
    for (char c : s) {
        // 如果是左括号，压入栈中
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } 
        // 如果是右括号
        else {
            // 栈为空说明没有对应的左括号
            if (st.empty()) {
                return false;
            }
            
            // 检查是否与栈顶的左括号匹配
            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop(); // 匹配成功，弹出栈顶元素
            } else {
                return false; // 不匹配
            }
        }
    }
    
    // 最后栈应该为空，表示所有括号都正确匹配
    return st.empty();
}

ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2){
     if (list1==nullptr)
    {
        return list2;
    }
    if (list2==nullptr)
    {
        return list1;
    }
    // 创建虚拟头结点，方便操作
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (list1 !=nullptr && list2 !=nullptr)
    {
        if (list1->val > list2->val)
        {
            /* code */
            tail->next =list2;
            list2 = list2->next;
        }else if (list1->val <= list2->val)
        {
            /* code */
            tail->next = list1;
            list1 = list1->next;
        }
        
        // 移动尾指针
         tail = tail->next;
    }

    // 可能有一个链表先为空，拼接另一条链表的剩余结点
    if (list1 != nullptr)
    {
        /* code */
        tail->next = list1;
    }else {
        tail->next = list2;
    }
    
    return dummy.next;
    // 将两个升序链表合并为一个新的 升序 链表并返回。
    // 新链表是通过拼接给定的两个链表的所有节点组成的。 
}

ListNode*  Solution::mergeKLists(vector<ListNode*>& lists){
    // 请你将所有链表合并到一个升序链表中，返回合并后的链表
    /*
    输入：lists = [[1,4,5],[1,3,4],[2,6]]
    输出：[1,1,2,3,4,4,5,6]
    解释：链表数组如下：
    [
    1->4->5,
    1->3->4,
    2->6
    ]
    将它们合并到一个有序链表中得到。
    1->1->2->3->4->4->5->6
    */

   // 使用优先队列（最小堆）来合并K个升序链表
   priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;

   // 将每个链表的头节点加入堆中
   for (ListNode* list : lists) {
       if (list != nullptr) {
           minHeap.push({list->val, list});
       }
   }

   // 创建虚拟头结点，方便操作
   ListNode dummy(0);
   ListNode* tail = &dummy;

   // 合并过程
   while (!minHeap.empty()) {
       // 取出堆顶元素（最小值）
       auto [val, node] = minHeap.top();
       minHeap.pop();

       // 将最小值节点加入结果链表
       tail->next = node;
       tail = tail->next;

       // 如果当前链表还有下一个节点，继续加入堆中
       if (node->next != nullptr) {
           minHeap.push({node->next->val, node->next});
       }
   }

   // 返回合并后的链表
   return dummy.next;
}

int Solution::removeDuplicates(vector<int>& nums){
    // 如果数组为空或只有一个元素，直接返回数组大小
    if (nums.size() <= 1) {
        return nums.size();
    }
    
    // 使用双指针技术
    // slow指针指向不重复元素的位置
    // fast指针用于遍历数组
    
    // 这里体现了vector可以随机访问的：使用数组下标进行访问
    int slow = 0;
    
    for (int fast = 1; fast < nums.size(); fast++) {
        // 当fast指针指向的元素与slow指针指向的元素不同时
        if (nums[fast] != nums[slow]) {
            // 移动slow指针
            slow++;
            // 将fast指针指向的元素复制到slow位置
            nums[slow] = nums[fast];
        }
    }
    
    // 返回不重复元素的个数
    return slow + 1;
}