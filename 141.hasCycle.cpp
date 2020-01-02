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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        if (head->next == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = slow->next;

        while(fast && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
            if (fast == slow) return true;
            fast = fast->next;
            if (fast == slow) return true;
        }

        return false;
    }
};