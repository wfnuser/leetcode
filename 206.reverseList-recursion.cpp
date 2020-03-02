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
    ListNode* tail;

    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) {
            tail = head;
            return head;
        }
        ListNode* next = head->next;
        reverseList(head->next);
        next->next = head;
        head->next = NULL;
        
        return tail;
    }
};