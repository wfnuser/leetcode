class MedianFinder {
public:

    priority_queue<int, vector<int>, greater<int>> right;
    priority_queue<int> left;
    int size = 0;

    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        size++;
        left.push(num);
        int mid = left.top();
        left.pop();
        right.push(mid);

        if (size % 2) {
            mid = right.top();
            right.pop();
            left.push(mid);
        }
    }
    
    double findMedian() {
        if (size % 2) {
            return left.top();
        } else {
            return (left.top() + right.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */