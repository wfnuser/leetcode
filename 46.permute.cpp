class Solution {
public:
    vector<vector<int>> ans;

    void search(int pos, vector<int> check, vector<int> path, vector<int> nums) {
        if (pos>=check.size()) {
            ans.push_back(path);        
        }
        for(int i = 0; i<check.size(); i++) {
            if(check[i]) {
                check[i] = 0;
                path.push_back(nums[i]);
                search(pos+1, check, path, nums);
                path.pop_back();
                check[i] = 1;
            }
        }
    };

    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        search(0, vector<int>(size,1), vector<int>(), nums);
        return ans;
    }
};