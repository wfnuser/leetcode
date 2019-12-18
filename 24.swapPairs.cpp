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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;

        ListNode* s = dummy->next;
        if (s==NULL) return head;
        ListNode* f = s->next;
        if (f == NULL) return head;

        while(f != NULL) {
            ListNode* next = f->next;
            f->next = s;
            s->next = next;
            before->next = f;

            before = s;
            s=s->next;
            if (s == NULL) break;
            f=s->next;
        }

        return dummy->next;
    }
};