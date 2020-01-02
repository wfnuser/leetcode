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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head->next;
        while(cur) {
            ListNode* it = dummy->next;
            ListNode* pre = dummy;
            while(it!=cur && it->val < cur->val) {
                pre = it;
                it=it->next;
            }
            if (it == cur) {
                cur = cur->next; 
                continue;
            }
            ListNode* last = cur->next;
            ListNode* next = pre->next;
            pre->next = cur;
            cur->next = next;
            while(it && it->next != cur) it = it->next;
            if(it) it->next = last;
            cur = last;
        }
        return dummy->next;
    }
};