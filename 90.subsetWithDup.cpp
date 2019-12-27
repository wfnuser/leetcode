class Solution {
public:
    vector<vector<int>> ans;

    void search(int start, int n, vector<int> path, vector<int> nums) {
        if (start >= n) {
            ans.push_back(path);
            return;
        }
        int i = start;
        path.push_back(nums[i]);
        i++;    
        while(i<n && nums[i] == nums[i-1]) {path.push_back(nums[i]);i++;}
        if (i==n) {
            ans.push_back(path);
            return;
        }
        while (i<=n) {
            search(i, n, path, nums);
            i++;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0) return vector<vector<int>>(0, vector<int>());
        sort(nums.begin(), nums.end());
        for (int i=0; i<=nums.size(); i++) {
            search(i, nums.size(), vector<int>(), nums);
        }

        return ans;
    }
};