class CQueue {
public:
    stack<int> q;
    stack<int> qq;

    CQueue() {

    }
    
    void appendTail(int value) {
        if (q.empty()) {
            while (!qq.empty()) {
                int val = qq.top();
                qq.pop();
                q.push(val);
            }
        }
        q.push(value);
    }
    
    int deleteHead() {
        while(!q.empty()) {
            int val = q.top();
            q.pop();
            qq.push(val);
        }
        if (qq.empty()) return -1;
        int val = qq.top();
        qq.pop();
        
        return val;        
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */