class MinStack {
public:

    stack<int> MIN;
    stack<int> S;

    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        S.push(x);
        if (MIN.empty() || MIN.top() > x) {
            MIN.push(x);
        } else {
            MIN.push(MIN.top());
        }
    }
    
    void pop() {
        MIN.pop();
        S.pop();
    }
    
    int top() {
        return S.top();
    }
    
    int min() {
        return MIN.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */