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
    ListNode* partition(ListNode* head, int x) {
        ListNode* firstLarger = head;
        ListNode* firstLargerPre = NULL;

        while(firstLarger != NULL) {
            if(firstLarger->val >= x) {
                break;
            }
            firstLargerPre = firstLarger;
            firstLarger = firstLarger->next;
        }

        if (firstLarger == NULL) return head;

        ListNode* cur = firstLarger->next;
        ListNode* pre = firstLarger;

        while(cur != NULL) {
            if (cur->val >= x) {
                pre = cur;
                cur = cur->next;
            } else {
                pre->next = cur->next;
                if (firstLargerPre == NULL) head = cur;
                if (firstLargerPre != NULL) firstLargerPre->next = cur;
                cur->next = firstLarger;
                firstLargerPre = cur;
                cur = pre->next;
            }
        }

        return head;
    }
};
