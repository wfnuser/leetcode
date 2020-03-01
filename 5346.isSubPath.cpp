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
    
    bool isSubContinuousPath(ListNode* head, TreeNode* root) {
        if (head == NULL) return true;
        if (root == NULL) return false;
        bool flag = false;
        if (head->val == root->val) {
            return isSubContinuousPath(head->next, root->left) || isSubContinuousPath(head->next, root->right);
        }
        return false;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == NULL) return true;
        if (root == NULL) return false;
        
        if (head->val == root->val) {
            bool cur = isSubContinuousPath(head->next, root->left) || isSubContinuousPath(head->next, root->right);
            if (cur) return true;
        }
        
        return isSubPath(head, root->left) || isSubPath(head, root->right);
        
    }
};