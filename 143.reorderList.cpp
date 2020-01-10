/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (53.90%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 25.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 * 
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
    void reorderList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        if (head == NULL || head->next == NULL || head->next->next == NULL) return;

        ListNode* tail = head;
        
        stack<ListNode*> s;
        queue<ListNode*> q;


        while(tail) {
            s.push(tail);
            q.push(tail);
            tail = tail->next;
        }


        ListNode* p = dummy;
        while(true) {
            if (s.top() == q.front()) {
                p->next = s.top();
                p->next->next = NULL;
                break;
            }
            if (q.front()->next == s.top()) {
                p->next = q.front();
                p = p->next;
                p->next = s.top();
                p = p->next;
                p->next = NULL;
                break;
            }
            p->next = q.front();
            p = p->next;
            p->next = s.top();
            p=p->next;

            q.pop();
            s.pop();
        }

        head = dummy->next;
    }
};
// @lc code=end

