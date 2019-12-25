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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = dummyHead;
        if (head!=NULL && head->val == 0) {
            dummyHead->val = -1;
        }

        while(cur!=NULL && cur->next!=NULL) {
            if (cur->next->val != cur->val) {
                p->next = cur;
                p=p->next;
            }
            while(cur->next != NULL && cur->next->val == cur->val) {
                cur = cur->next;
            }
            cur = cur->next;
        }
        if (cur!=NULL && cur->val!=p->val) {
            p->next = cur;
            p=p->next;
        }
        p->next = NULL;

        return dummyHead->next;
    }
};