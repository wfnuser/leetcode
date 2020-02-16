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
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        prev->next = NULL;
        while (curr != NULL) {
            ListNode* node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = node;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl1 = reverse(l1);
        ListNode* rl2 = reverse(l2);

        ListNode* p1 = rl1;
        ListNode* p2 = rl2;
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;

        int carry = 0;
        while(p1&&p2) {
            p->val = carry + p1->val + p2->val;
            carry = p->val / 10;
            p->val %= 10;
            p->next = new ListNode(0);
            p = p->next;
            p1 = p1->next;
            p2 = p2->next;
        }

        while(p1) {
            p->val = carry + p1->val;
            carry = p->val / 10;
            p->val %= 10;
            p->next = new ListNode(0);
            p = p->next;
            p1 = p1->next;
        }
        while(p2) {
            p->val = carry + p2->val;
            carry = p->val / 10;
            p->val %= 10;
            p->next = new ListNode(0);
            p = p->next;
            p2 = p2->next;
        }
        if (carry) {
            p->val = carry;
            p->next = new ListNode(0);
            p = p->next;
        }

        dummy = reverse(dummy);
        return dummy->next;
    }


};