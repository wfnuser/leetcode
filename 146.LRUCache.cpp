class Node {
    public:
        Node* next;
        Node* pre;
        int key;
        int val;
};

class LRUCache {
public:
    unordered_map<int, Node*> m;
    Node* head;
    Node* tail;
    int size = 0;
    int cap = 0;

    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->key = 123123;
        tail->key = 456456;
        head->next = tail;
        tail->pre = head;
        cap = capacity;
    }
    
    int get(int key) {        
        if (m[key]) {
            if (m[key]->pre != head) {
                Node* next = head->next;
                m[key]->pre->next = m[key]->next;
                m[key]->next->pre = m[key]->pre;
                m[key]->pre = head;
                head->next = m[key];
                m[key]->next = next;
                next->pre = m[key];
            }
            return m[key]->val;
        } else return -1;
    }
    
    void put(int key, int value) {
        if (m[key]) {
            m[key]->val = value;
            if (m[key]->pre != head) {
                Node* next = head->next;
                m[key]->pre->next = m[key]->next;
                m[key]->next->pre = m[key]->pre;
                m[key]->pre = head;
                head->next = m[key];
                m[key]->next = next;
                next->pre = m[key];
            }
            return;
        }
        size++;
        if (size > cap) {
            size--;
            Node* pre = tail->pre;
            tail->pre = pre->pre;
            tail->pre->next = tail;
            m.erase(pre->key);
        }
        Node* n = new Node();
        n->next = head->next;
        n->pre = head;
        head->next = n;
        n->next->pre = n;
        n->key = key;
        n->val = value;
        m[key] = n;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */