class MaxQueue {
public:
    deque<int> MAX;
    queue<int> Q;

    MaxQueue() {
    }
    
    int max_value() {
        if (Q.empty()) return -1;
        return MAX.front();
    }
    
    void push_back(int value) {
        while(!MAX.empty()) {
            if (MAX.back() < value) MAX.pop_back();
            else break;
        }
        MAX.push_back(value);
        Q.push(value);
    }
    
    int pop_front() {
        if (Q.empty()) return -1;
        if (Q.front() >= MAX.front()) {
            MAX.pop_front();
        }
        int ans = Q.front();
        Q.pop();
        return ans;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */