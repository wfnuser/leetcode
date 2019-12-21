class Solution {
public:
    vector<vector<int>> ans;
    map<int, int> cnt;         

    void printPath(vector<int> path) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    void search(int pos, vector<int> nums, vector<int> path) {
        // printPath(path);
        if (pos >= nums.size()) ans.push_back(path);
        for (int i = 0; i<nums.size(); i++) {
            if (i>0 && nums[i-1] == nums[i]) continue;
            if (cnt[nums[i]] > 0) {
                cnt[nums[i]]--;
                path.push_back(nums[i]);
                search(pos+1, nums, path);
                path.pop_back();
                cnt[nums[i]]++;
            } 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i<nums.size(); i++) {
            if (cnt.find(nums[i]) != cnt.end()) {
                cnt[nums[i]] += 1;
            } else {
                cnt[nums[i]] = 1;
            }
        }
        search(0, nums, vector<int>());

        return ans;
    }
};