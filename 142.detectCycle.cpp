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
        if (head == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        int flag = -1;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
            if (fast == slow) {
                flag = 1;
                break;
            }
        }

        if (flag == -1) return NULL;

        fast = slow;
        slow = head;
        while(fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};