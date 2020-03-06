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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* p = new ListNode(0);
        ListNode* list = p;
        
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        while(p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                p->next = new ListNode(p1->val);
                p1 = p1->next;
                p = p->next;
            } else {
                p->next = new ListNode(p2->val);
                p2 = p2->next;
                p = p->next;
            }
            if (p1 == NULL) {
                p->next = p2;
            }
            if (p2 == NULL) {
                p->next = p1;
            }
        }

        if (list->next == NULL){
            if (p1==NULL) return p2;
            return p1;
        }

        return list->next;
    }
};