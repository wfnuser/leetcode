/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* p;
    Node* dummy;

    void dfs(Node* node) {
        p->next = new Node();
        p->next->val = node->val;
        p->next->prev = p;
        p = p->next;

        if (node->child != NULL) {
            dfs(node->child);
        }
        if (node->next != NULL) {
            dfs(node->next);
        }
    }

    Node* flatten(Node* head) {
        if (head == NULL) return NULL;
        p = new Node();
        dummy = p;
        dfs(head);
        p->next = NULL;
        dummy->next->prev = NULL;
        p = dummy->next;
        while(p != NULL) {
            p->child = NULL;
            p = p->next;
        }
        return dummy->next;
    }
};