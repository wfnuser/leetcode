class Solution {
private:
    vector<int> origin;
public:
    static bool compare(const pair<int, int> &p1,const pair<int, int> &p2) {
        if (p1.first > p2.first) return true;
        if (p1.first == p2.first) {
            return rand()%2 == 1;
        }
        return false;
    }

    Solution(vector<int>& nums) {
        origin = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> s = origin;
        for (int i = 1; i < s.size(); i++) {
            int exchange = rand() % (i+1);
            if (exchange != i) {
                int tmp = s[exchange];
                s[exchange] = s[i];
                s[i] = tmp;
            }
        }

        return s;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */