class MovingAverage {
public:
    int sum = 0;
    int cnt = 0;
    queue<int> q;
    int max = 0;

    /** Initialize your data structure here. */
    MovingAverage(int size) {
        max = size;
    }
    
    double next(int val) {
        sum += val;
        cnt++;
        q.push(val);
        if (cnt > max) {
            cnt = max;
            sum -= q.front();
            q.pop();
        }
        return (0.0+sum) / cnt;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */