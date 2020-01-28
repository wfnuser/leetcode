class HitCounter {
public:

    int size = 0;
    queue<int> q;
    unordered_map<int, int> m;
    
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (!m[timestamp]) {
            q.push(timestamp);
        }
        m[timestamp]++;
        size++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!q.empty()&&q.front()<=timestamp-300) {
            size -= m[q.front()];
            q.pop();
        }

        return size;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */