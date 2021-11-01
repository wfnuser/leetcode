class Event {
public:
    int type;
    int time;
    int val;

    Event(int type, int time, int val) {
        this->type = type;
        this->time = time;
        this->val = val;
    }
};

void quicksort(vector<Event>& v, int left, int right) {
    if (left >= right) return;
    int target = rand() % (right - left + 1);
    swap(v[left+target], v[left]);

    Event pivot = v[left];
    int slow = left;
    int fast = left+1;

    while (fast <= right) {
        if (v[fast].time > pivot.time || (v[fast].time == pivot.time && v[fast].type >= pivot.type)) {
            if (v[fast].time > pivot.time || v[fast].type > pivot.type || rand()%2) {
                fast++;
                continue;
            }
        }
        slow++;
        Event tmp = v[fast];
        v[fast] = v[slow];
        v[slow] = tmp;
        fast++;
    }

    v[left] = v[slow];
    v[slow] = pivot;
    
    quicksort(v, left, slow-1);
    quicksort(v, slow+1, right);

    return;
}

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<Event> v;
        v.resize(events.size() * 2, Event(0,0,0));
        int i = 0;
        for (auto e: events) {
            v[i++] = Event(0, e[0], e[2]);
            v[i++] = Event(1, e[1], e[2]);
        }
        quicksort(v, 0, v.size() - 1);
        
        int ans = 0;
        int lartest = 0;

        for (auto e: v) {
            if (e.type == 0) {
                ans = max(ans, lartest + e.val);
            } else {
                lartest = max(lartest, e.val);
            }
        }
        
        return ans;
    }
};