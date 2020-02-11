class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.size() == 0) {
                s.push(nums[i]);
            } else if (s.size() == 1){
                if (nums[i] > s.top()) {
                    s.push(nums[i]);
                } else {
                    s.pop();
                    s.push(nums[i]);
                }
            } else if (s.size() == 2) {
                if (nums[i] >= s.top()) {
                    s.pop();
                    s.push(nums[i]);
                } else {
                    int second = s.top();
                    s.pop();
                    int first = s.top();
                    s.pop();
                    for (int j =i; j < nums.size(); j++) {
                        if (nums[j] < second && nums[j] > first) {
                            return true;
                        }
                    }
                    s.push(nums[i]);
                }
            }
        }
        return false;
    }
};