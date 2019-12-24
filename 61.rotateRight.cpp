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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0) return head;
        int len = 0;
        ListNode* iter = head;
        while(true) {
            if (iter!=NULL) {
                len++;
                iter = iter->next;
            }
            else break;
        }
        if (len == 0) return head;

        k = k % len;
        if (k == 0) return head;

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;

        for(int i = 0; i < k; i++) {
            fast = fast->next;
            if (fast == NULL) return head;
        }

        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = dummyHead->next;
        ListNode* first = slow->next;
        slow->next = NULL;

        return first;
    }
};