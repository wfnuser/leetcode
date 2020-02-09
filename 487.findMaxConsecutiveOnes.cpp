class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> parts;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (cnt < 0) {
                    parts.push_back(cnt);
                    cnt = 0;
                }
                cnt++;
            } else {
                if (cnt > 0) {
                    parts.push_back(cnt);                
                    cnt = 0;
                }
                cnt--;
            }
        }
        parts.push_back(cnt);

        int ans = 0;
        if (parts.size() == 0) return 0;
        if (parts.size() == 1) {
            if (parts[0] > 0) return parts[0];
            else return 1;
        }

        for (int i = 0; i < parts.size(); i++) {
            int j = i+1;
            if (parts[i] < 0) {
                ans = max(ans, 1);
                if (j<parts.size()) ans = max(parts[j]+1, ans);
            } else {
                ans = max(ans, parts[i]);
                if (j >= parts.size()) continue;
                ans = max(ans, parts[i]+1);
                if (j+1 >= parts.size()) continue;
                if (parts[j] == -1) {
                    ans = max(ans, parts[i]+1+parts[j+1]);
                }
            }
        }

        return ans;
    }
};