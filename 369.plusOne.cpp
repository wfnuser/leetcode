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

    int plus(ListNode* node) {
        if (node->next) {
            int carry = plus(node->next);
            if (carry) {
                int val = node->val;
                val++;
                int carry = val / 10;
                node->val = val % 10;
                return carry;
            } else {
                return 0;
            }
        } else {
            int val = node->val;
            val++;
            int carry = val / 10;
            node->val = val % 10;
            return carry;
        }
    }

    ListNode* plusOne(ListNode* head) {
        if (head==NULL) return NULL;
        int carry = plus(head);
        if (carry == 0) return head;
        ListNode* dummy = new ListNode(head->val);
        dummy->next = head->next;
        head->val = carry;
        head->next = dummy;
        return head;
    }
};