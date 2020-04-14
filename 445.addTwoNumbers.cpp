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

    ListNode* reverse(ListNode* l) {
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        ListNode* cur = l;
        dummy->next = l;

        while(cur->next) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        cur->next = pre;
        l->next = NULL;

        return cur;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode* rl1 = reverse(l1);
        ListNode* rl2 = reverse(l2);

        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;

        ListNode* p1 = rl1;
        ListNode* p2 = rl2;

        int carry = 0;
        while(p1 && p2) {
            int sum = p1->val + p2->val + carry;
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            p1 = p1->next;
            p2 = p2->next;
        }

        while(p1) {
            int sum = p1->val + carry;
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            p1 = p1->next;
        }
        while(p2) {
            int sum = p2->val + carry;
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            p2 = p2->next;
        }
        if (carry) {
            p->next = new ListNode(carry);
            p = p->next;
        }
        
        ListNode* ans = reverse(dummy->next);

        return ans;
    }
};