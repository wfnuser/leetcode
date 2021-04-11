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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        if (k <= 1) return head;

        // ListNode* pre = dummy->next;
        // ListNode* cur = pre->next;
        // ListNode* next = cur->next;

        ListNode* start = dummy;
        ListNode* end = dummy;

        while(true) {
            for (int i = 0; i < k && end != NULL; i++) {end = end->next;}
            if (!end) break;
            
            ListNode* nextStart = end->next;
            end->next = NULL;

            ListNode* pre = start;
            ListNode* cur = start->next;
            ListNode* last = start->next;
            while(cur != NULL) {
                ListNode* next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }

            start->next = pre;
            last->next = nextStart;
            start = last;
            end = last;
        }

        return dummy->next;
    }
};