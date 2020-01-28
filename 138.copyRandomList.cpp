/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> copyNode;

    Node* copy(Node* node) {
        return new Node(node->val);
    }

    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* chead = new Node(head->val);

        Node* p = head->next;
        Node* cp = chead;
        copyNode[head] = chead;
        while(p) {
            cp->next = copy(p);
            cp = cp->next;
            copyNode[p] = cp;
            p = p->next;
        }

        cp = chead;
        p = head;
        while(cp) {
            cp->random = copyNode[p->random];
            cp = cp->next;
            p = p->next;
        }

        return chead;
    }
};