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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers(l1, l2, 0);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && carry == 0) {
            return NULL;
        }
        int val = carry + (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0);
        auto res = new ListNode(val % 10);
        res -> next = addTwoNumbers((l1 ? l1 -> next : NULL), (l2 ? l2 -> next : NULL), val / 10);
        return res;
    }
};