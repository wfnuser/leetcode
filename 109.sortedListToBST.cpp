/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* listToTree(ListNode* head) {
        TreeNode* root = new TreeNode(0);
        if (head == NULL) return NULL;
        if (head->next == NULL) {
            root->val = head->val;
            return root;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* pre = NULL;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        root->val = slow->val;
        
        if (pre) {
            pre->next = NULL;
            root->left = listToTree(head);
        }
        root->right = listToTree(slow->next);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return listToTree(head);
    }
};