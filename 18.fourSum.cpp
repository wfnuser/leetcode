class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, vector<pair<int, int>>> cnts;
        vector<vector<int>> ans;
        unordered_map<string, int> visited;
        sort(nums.begin(), nums.end());

        int N = nums.size();
        for (int a = 0; a < N; a++) {
            for (int b = a+1; b < N; b++) {
                cnts[target - nums[a] - nums[b]].push_back(make_pair(a,b));
                while(b+1<N && nums[b+1] == nums[b]) b++;
            }
        }

        for (int c = 0; c < N; c++) {
            for (int d = c+1; d < N; d++) {
                int sum = nums[c] + nums[d];
                for (auto p: cnts[sum]) {
                    if (c <= p.second) continue;
                    if (!visited[to_string(nums[p.first])+"-"+to_string(nums[p.second])+"-"+to_string(nums[c])+"-"+to_string(nums[d])]) ans.push_back(vector<int>{nums[p.first], nums[p.second], nums[c], nums[d]});
                    visited[to_string(nums[p.first])+"-"+to_string(nums[p.second])+"-"+to_string(nums[c])+"-"+to_string(nums[d])] = 1;
                }
            }
        }

        return ans;
    }
};