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
    unordered_map<int, int> cnt;

    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* p = head;

        while(p != NULL) {
            cnt[p->val]++;
            if (p->next == NULL) break;
            if (cnt[p->next->val]) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }

        return head;
    }
};