#include "Solution.h"
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
#include <stdexcept>
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

// 辅助函数：将整数转换为二进制字符串
string intToBinary(int n) {
    if (n == 0) return "0";
    
    string binary = "";
    while (n > 0) {
        binary = (n % 2 ? '1' : '0') + binary;
        n /= 2;
    }
    return binary;
}

string Solution::convertDateToBinary(string date) {
    // 验证日期格式 (YYYY-MM-DD)
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        throw invalid_argument("Invalid date format. Expected YYYY-MM-DD");
    }
    
    // 将日期字符串拆分为年、月、日
    string yearStr = date.substr(0, 4);
    string monthStr = date.substr(5, 2);
    string dayStr = date.substr(8, 2);
    
    // 检查各部分是否都是数字
    for (char c : yearStr + monthStr + dayStr) {
        if (!isdigit(c)) {
            throw invalid_argument("Date components must be numeric");
        }
    }
    
    // 将年、月、日转换为整数
    int y = stoi(yearStr);
    int m = stoi(monthStr);
    int d = stoi(dayStr);
    
    // 验证年份范围
    if (y < 1900 || y > 2100) {
        throw invalid_argument("Year must be between 1900 and 2100");
    }
    
    // 验证月份范围
    if (m < 1 || m > 12) {
        throw invalid_argument("Month must be between 1 and 12");
    }
    
    // 验证日期范围
    if (d < 1 || d > 31) {
        throw invalid_argument("Day must be between 1 and 31");
    }
    
    // 验证具体的日期是否有效（考虑每月天数和闰年）
    // 每月的天数（非闰年）
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // 检查是否为闰年
    bool isLeapYear = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    
    // 如果是闰年，2月有29天
    if (isLeapYear) {
        daysInMonth[1] = 29;
    }
    
    // 验证日期是否超过当月最大天数
    if (d > daysInMonth[m - 1]) {
        throw invalid_argument("Invalid day for the given month and year");
    }

    // 将年、月、日直接转换为二进制字符串
    string binaryYear = intToBinary(y);
    string binaryMonth = intToBinary(m);
    string binaryDay = intToBinary(d);

    string binaryDate = binaryYear + "-" + binaryMonth + "-" + binaryDay;

    return binaryDate;
}

int Solution::runeReserve(vector<int> runes){
    if(runes.size()<=1)
    return runes.size();
    sort(runes.begin(),runes.end());
    int max_len{1};
    int cur_len{1};
    for(int i{1};i<runes.size();++i){
        if(runes[i] <= runes[i-1]+1){
            // 满足条件
            ++cur_len;
        }else{
            // 不满足条件，更新子串中相差为1的最大长度
            max_len = max(max_len,cur_len);
            cur_len = 1;  // 重置当前长度
        }
    }
    max_len = max(max_len,cur_len);
    return max_len;
}
string Solution::longestPalindrome(string s){
    // 给你一个字符串 s，找到 s 中最长的 回文 子串。
    if (s.empty()) {
        return "";
    }
    int start = 0, maxLength = 1;
    for (int i{0};i<s.size();i++){
        // 处理奇数长度回文
        this->expand(s, i, i, start, maxLength);
        // 处理偶数长度回文
        this->expand(s, i, i+1, start, maxLength);
    }
    return s.substr(start, maxLength);
}
void Solution::expand(const string& s, int l, int r, int& start, int& max_len) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        l--;
        r++;
    }
    int len = r - l - 1;
    if (len > max_len) {
        max_len = len;
        start = l + 1;
    }
}

int Solution::arithmeticTriplets(vector<int>& nums, int diff){
    // 给你一个下标从 0 开始、严格递增 的整数数组 nums 和一个正整数 diff 。
    // 如果满足下述全部条件，则三元组 (i, j, k) 就是一个 等差三元组 ：
    if(nums.size() <= 2)return 0;
    int count{0};
    set<int> s(nums.begin(),nums.end());
    for(const auto& num:nums){
        if(s.find(num+diff) != s.end() && s.find(num+2*diff) != s.end()){
            count++;
        }
    }
    return count;
    
}
bool Solution::divisorGame(int n){
    // 爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。

    // 最初，黑板上有一个数字 n 。在每个玩家的回合，玩家需要执行以下操作：

    // 选出任一 x，满足 0 < x < n 且 n % x == 0 。
    // 用 n - x 替换黑板上的数字 n 。
    // 如果玩家无法执行这些操作，就会输掉游戏。

    // 只有在爱丽丝在游戏中取得胜利时才返回 true 。假设两个玩家都以最佳状态参与游戏。
    return n%2==0;
}

int Solution::earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
//     给你两种类别的游乐园项目：陆地游乐设施 和 水上游乐设施。

// 陆地游乐设施
// landStartTime[i] – 第 i 个陆地游乐设施最早可以开始的时间。
// landDuration[i] – 第 i 个陆地游乐设施持续的时间。
// 水上游乐设施
// waterStartTime[j] – 第 j 个水上游乐设施最早可以开始的时间。
// waterDuration[j] – 第 j 个水上游乐设施持续的时间。
// 一位游客必须从 每个 类别中体验 恰好一个 游乐设施，顺序 不限 。

// 游乐设施可以在其开放时间开始，或 之后任意时间 开始。
// 如果一个游乐设施在时间 t 开始，它将在时间 t + duration 结束。
// 完成一个游乐设施后，游客可以立即乘坐另一个（如果它已经开放），或者等待它开放。
// 返回游客完成这两个游乐设施的 最早可能时间 
    int min_time = INT_MAX;
    // 遍历所有可能的陆地游乐设施开始时间
    for(int i{0};i<landStartTime.size();++i){
        // 遍历所有可能的水上游乐设施开始时间
        for (int j = 0; j < waterStartTime.size(); ++j) {
                // 先陆地后水上
                int landEnd = landStartTime[i] + landDuration[i];
                int waterStart = max(landEnd, waterStartTime[j]);
                int case1 = waterStart + waterDuration[j];
                
                // 先水上后陆地
                int waterEnd = waterStartTime[j] + waterDuration[j];
                int landStart = max(waterEnd, landStartTime[i]);
                int case2 = landStart + landDuration[i];
                
                min_time = min(min_time, min(case1, case2));
            }
    }
    return min_time;
}

int Solution::divide(int a, int b){
    // 给定两个整数 a 和 b ，求它们的除法的商 a/b ，
    // 要求不得使用乘号 '*'、除号 '/' 以及求余符号 '%' 。
    if (a == 0) return 0;
    if (b == 0) throw invalid_argument("Division by zero is not allowed.");
    if (a == INT_MIN && b == -1) return INT_MAX;

    // 使用异或运算符确定结果的符号
    bool sign = (a < 0) ^ (b < 0);
    // 转换为正数运算（使用long防止溢出）
    long long dividend = labs(a);
    long long divisor = labs(b);

    int result = 0;
    while (dividend >= divisor){
        long temp = divisor;     //  除数的倍数
        long multiple = 1;      // 倍数计数器
        // 找到最大的2^n倍除数
        while (temp <= (dividend >> 1)) {
        temp <<= 1;
        multiple <<= 1;
        }
        dividend -= temp;
        result += multiple;
    }
    return sign ? -result : result;
}