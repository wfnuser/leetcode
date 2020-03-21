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
    vector<ListNode*> min_heap;
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        for (auto node: lists) {
            if (node) push(node);
        }

        while(min_heap.size()) {
           ListNode* node = pop();
           if (node == NULL) continue;
           if (node->next) {
               push(node->next);
           }
           cur->next = node;
           cur = cur->next;
        }

        return dummy->next;
    }

    ListNode* pop() {
        ListNode* res = min_heap[0];
        int size = min_heap.size();
        min_heap[0] = min_heap[size-1];
        min_heap.pop_back();

        int i = 0;
        size = min_heap.size();
        while((2*i+1)<size) {
            int pos = 2*i + 1;
            if (pos+1 < min_heap.size() && min_heap[pos+1]->val <= min_heap[pos]->val) {
                pos++;
            }
            if (min_heap[i]->val <= min_heap[pos]->val) break;     
            swap(min_heap[i], min_heap[pos]);                      
            i = pos;  
        }

        return res;
    }

    void push(ListNode* node) {
        min_heap.push_back(node);
        int i = min_heap.size() - 1;

        while(i > 0) {
            int parent = (i-1) / 2;
            if (min_heap[parent]->val > min_heap[i]->val) swap(min_heap[i], min_heap[parent]);
            else break;
            i = parent;
        }
    }
};