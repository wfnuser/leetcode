class Solution {
public:
    bool isSmaller(string a, string b) {
        if (a == b) return true;
        int i = 0;
        int j = 0;
        while(i <= max(a.size(), b.size())) {
            if (a[i % a.size()] < b[i % b.size()]) return true;
            if (a[i % a.size()] > b[i % b.size()]) return false;
            i++;
        }

        return true;
    }

    void sort(vector<string>& nums, int left, int right) {
        if (left >= right) return;

        int slow = left;
        int fast = left+1;

        string pivot = nums[left];

        while(fast <= right) {
            if (isSmaller(nums[fast], pivot)) {
                slow++;
                string tmp = nums[fast];
                nums[fast] = nums[slow];
                nums[slow] = tmp;
            }
            fast++;
        }

        nums[left] = nums[slow];
        nums[slow] = pivot;

        sort(nums, left, slow-1);
        sort(nums, slow+1, right);
    }


    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto num: nums) strs.push_back(to_string(num));

        sort(strs, 0, nums.size() - 1);

        string ans = "";
        for (auto num: strs) {
            ans += num;
        }

        return ans;
    }
};