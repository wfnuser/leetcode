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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i=1;i<=n;i++) {
            fast = fast->next;
        }
        if(fast == NULL) {
            slow = slow->next;
            return slow;
        }

        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        } 
        slow->next = slow->next->next;

        return head;
    }
};