class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        vector<string> ans;
        if (lower == upper) {
            if (size == 0) {
                ans.push_back(to_string(lower));
            }
            return ans;
        }
        if (size == 0)  {
            ans.push_back(to_string(lower)+"->"+to_string(upper));
            return ans;
        };
        int pre;
        if (nums[0] > lower) {
            if (nums[0] > lower+1) {
                ans.push_back(to_string(lower)+"->"+to_string(nums[0]-1));
            } else {
                ans.push_back(to_string(lower));
            }
        }

        for (int i = 1; i < size; i++) {
            
            if (nums[i] == nums[i-1]) continue;
            if (nums[i] <= nums[i-1]+1) continue;
            if (nums[i] == nums[i-1]+2) ans.push_back(to_string(nums[i]-1));
            else ans.push_back(to_string(nums[i-1]+1)+"->"+to_string(nums[i]-1));
        }

        if (nums[size-1] < upper) {
            if (nums[size-1] < upper-1) {
                ans.push_back(to_string(nums[size-1]+1)+"->"+to_string(upper));
            } else {
                ans.push_back(to_string(upper));
            }
        }

        return ans;
    }
};