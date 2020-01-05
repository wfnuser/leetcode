class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> appeared;
        for (auto num: nums) {
            appeared.insert(pair<int, int>(num,1));
        }

        int ans = 0;

        for (auto num: nums) {
            if(appeared.find(num) == appeared.end()) continue;
            appeared.erase(num);
            int cnt = 1;
            int l = num+1;
            int s = num-1;
            while(appeared.find(l) != appeared.end()) {
                appeared.erase(l);
                l++;
                cnt++;
            }

            while(appeared.find(s) != appeared.end()) {
                appeared.erase(s);
                s--;
                cnt++;
            }
            if (cnt>ans) ans = cnt;
        }

        return ans;
    }
};