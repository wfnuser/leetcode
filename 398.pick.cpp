class Solution {
public:

    unordered_map<int, int> firstIndex;
    unordered_map<int, int> lastIndex;
    unordered_map<int, int> count;

    vector<int>* numList;

    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            if (firstIndex.find(nums[i]) == firstIndex.end()) {
                firstIndex[nums[i]] = i;
                lastIndex[nums[i]] = i;
                nums[i] = i;
            } else {
                nums[lastIndex[nums[i]]] = i;
                lastIndex[nums[i]] = i;
            }
        }
        numList = &nums;
    }
    
    int pick(int target) {
        if (count[target] == 1) return firstIndex[target];
        else {
            int r = rand() % count[target];
            int ans = firstIndex[target];
            for (int i = 0; i < r; i++) {
                ans = (*numList)[ans];
            }
            return ans;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */