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
    Node* copyRandomList(Node* head) {
        if (head == NULL) return head;
        
        unordered_map<Node*, Node*> rnd;

        Node* fakeHead = new Node(head->val);

        Node* p = head;
        Node* fp = fakeHead;

        while(p != NULL) {
            rnd[p] = fp;
            p = p->next;
            if (p == NULL) fp->next = NULL;
            else {
                Node* next = new Node(p->val);
                fp->next = next;
            }
            fp = fp->next;
        }

        p = head;
        fp = fakeHead;
        while(p != NULL) {
            fp->random = rnd[p->random];
            p = p->next;
            fp = fp->next;
        }

        return fakeHead;
    }
};