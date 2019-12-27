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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        if (head->next == NULL) return head;
        if (head->next->next == NULL) {
            ListNode* next = head->next;
            next->next = head;
            head->next = NULL;
            return next;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = dummyHead->next;
        ListNode* next = cur->next;

        ListNode* first;
        ListNode* last;

        for (int i = 0; i < m-1; i++) {
            pre = pre->next;
        }
        cur = pre->next;
        next= cur->next;
        first = pre;
        last = cur; 
        for (int i = m-1; i < n; i++) {
            last = last->next;
        }

        cur->next = last;
        pre = cur;
        cur = next;
        next = next->next;
        for (int i = m + 1; i < n ; i++) {
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next->next;
        }
        cout << cur->val << endl;
        cur->next = pre;
        first->next = cur;

        return dummyHead->next;
    }
};