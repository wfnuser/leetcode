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

    void quick_sort(vector<int> &arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int pivot = arr[left];
        int slow = left;
        int fast = left+1;

        while(fast <= right) {
            if (arr[fast] < pivot) {
                slow++;
                int tmp = arr[fast];
                arr[fast] = arr[slow];
                arr[slow] = tmp;
            }
            fast++;
        }
        arr[left] = arr[slow];
        arr[slow] = pivot;

        quick_sort(arr, left, slow-1);
        quick_sort(arr, slow+1, right);
    }

    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* p = head;
        while(p) {
            arr.push_back(p->val);
            p = p->next;
        }
        
        quick_sort(arr, 0, arr.size()-1);
        p = head;
        for (auto num:arr) {
            p->val = num;
            p = p->next;
        }

        return head;
    }
};