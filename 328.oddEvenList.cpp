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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummyE = new ListNode(0);
        ListNode* dummyO = new ListNode(0);

        ListNode* p = head;
        ListNode* o = dummyO;
        ListNode* e = dummyE;

        while(p) {
            o->next = p;
            o = o->next;
            p = p->next;

            e->next = p;
            e = e->next;
            if (!p) break;
            p = p->next;    
        }
        o->next = NULL;
        o = dummyO;
        while(o->next) {
            o = o->next;
        }
        cout << endl;
        o->next = dummyE->next;

        return dummyO->next;
    }
};