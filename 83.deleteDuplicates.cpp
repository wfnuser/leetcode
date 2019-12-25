/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        if (dummyHead->next!=NULL && dummyHead->next->val == 0) {
            dummyHead->val = -1;
        } 
        ListNode* cur = dummyHead;
        while(cur->next != NULL) {
            if (cur->next->val == cur->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }

        return dummyHead->next;
    }
};
// @lc code=end

