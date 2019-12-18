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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* l = dummy;

        while(true) {
            if (l1 == NULL) {
                while (l2 != NULL) {
                    l->next = new ListNode(l2->val);
                    l=l->next;
                    l2 = l2->next;
                }
                break;
            }
            if (l2 == NULL) {
                while (l1 != NULL) {
                    l->next = new ListNode(l1->val);
                    l=l->next;
                    l1 = l1->next;
                }
                break;
            }
            int val1 = l1->val;
            int val2 = l2->val;
            if (val1>val2) {
                l->next = new ListNode(val2);
                l = l->next;
                l2 = l2->next;
            } else {
                l->next = new ListNode(val1);
                l = l->next;
                l1 = l1->next;
            }
        }

        return dummy->next;
    }
};