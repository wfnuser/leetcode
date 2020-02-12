class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;

        int slow = 0;
        int fast = nums.size() - 1;
        if (nums.size() <= 1) return;

        int middle = (nums.size()+1)/2;
        for (int i = 0; i < middle; i++) {
            if (i >= middle-1-i) break;
            int tmp = nums[i];
            nums[i] = nums[middle-1-i];
            nums[middle-1-i] = tmp;
        }

        while(slow < fast) {
            res.push_back(nums[slow++]);
            if (slow > fast) break;
            res.push_back(nums[fast--]);
        }
        if (nums.size() % 2 == 1) res.push_back(nums[slow]);

        nums = res;
        return;
    }
};