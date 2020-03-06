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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        if (head->next == NULL) return head;

        ListNode* cur = head;
        ListNode* res = reverseList(head->next);
        cur->next->next = cur;
        cur->next = NULL;

        return res;
    }
};