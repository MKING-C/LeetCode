#include <iostream>
#include "Solution.cpp"
using namespace std;

int main() {
    // 创建链表: 1 -> 2 -> 3 -> nullptr
    // 创建链表头节点，值为1
    ListNode* list1 = new ListNode(1);
    // 将第二个节点连接到第一个节点后，值为2
    list1->next = new ListNode(2);
    // 将第三个节点连接到第二个节点后，值为3
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(5);
    // list1->next->next->next->next = new ListNode(7);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    list2->next->next->next = new ListNode(6);
    
    // 遍历链表
    ListNode* current = list1; // current是指向当前节点的指针
    cout << "链表内容list1: ";
    while (current != nullptr) {
        // 输出当前节点的值
        cout << current->val << " ";
        // 移动到下一个节点
        current = current->next;
    }
    cout << endl;
    
    // 遍历链表
    current = list2; // current是指向当前节点的指针
    cout << "链表内容list2: ";
    while (current != nullptr) {
        // 输出当前节点的值
        cout << current->val << " ";
        // 移动到下一个节点
        current = current->next;
    }
    cout << endl;

    Solution solution;
    ListNode* list3 = nullptr;
    list3 = solution.mergeTwoLists(list1,list2);

    current = list3; // current是指向当前节点的指针
    cout << "合并后链表内容list3: ";
    while (current != nullptr) {
        // 输出当前节点的值
        cout << current->val << " ";
        // 移动到下一个节点
        current = current->next;
    }
    cout << endl;
    
    // 释放内存 - 只需要释放合并后的链表
    // 因为合并后的链表包含了原来两个链表的所有节点
    current = list3;
    while (current != nullptr) {
        // 暂存当前节点指针
        ListNode* temp = current;
        // 移动到下一个节点
        current = current->next;
        // 删除暂存的节点
        delete temp;
    }

    return 0;
}