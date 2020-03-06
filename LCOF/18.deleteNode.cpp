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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* cur = head;

        while(cur != NULL) {
            if (cur->val == val) {
                pre->next = cur->next;
                break;
            }
            cur = cur->next;
            pre = pre->next;
        }

        return dummy->next;
    }
};