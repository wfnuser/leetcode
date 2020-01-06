class TwoSum {
public:
    vector<int> v;
    /** Initialize your data structure here. */
    TwoSum() {
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        v.push_back(number);   
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        unordered_map<int, int> s;
        for (auto num: v) {
            s[num] += 1;
        }
        for (auto num: v) {
            int target = value - num;
            if (s[target]) {
                if (num == target && s[target] > 1) return true;
                if (num != target) return true; 
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */