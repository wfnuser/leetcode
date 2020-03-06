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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;

        int lenA = 0;
        int lenB = 0;

        while(pA != NULL) {
            lenA++;
            pA = pA->next;
        }
        while(pB != NULL) {
            lenB++;
            pB = pB->next;
        }

        pA = headA;
        pB = headB;

        if (lenA < lenB) {
            for (int i = 0; i < lenB-lenA; i++) pB = pB->next;
        } else {
            for (int i = 0; i < lenA-lenB; i++) pA = pA->next;
        }

        while(pA != NULL && pB != NULL) {
            if (pA == pB) return pA;
            pA = pA->next;
            pB = pB->next;
        }

        return NULL;
    }
};