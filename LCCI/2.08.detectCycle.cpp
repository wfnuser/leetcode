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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        if (fast != slow) return NULL;
        fast = head;
        // slow = slow->next;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }

};
