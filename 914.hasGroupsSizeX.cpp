class Solution {
public:
    
    unordered_map<int, int> cnt;
    vector<int> nums;

    int gcd(int a, int b) {
        if (a < b) return gcd(b, a);
        if (b == 1) return 1;
        if (a % b == 0) return b;
        return gcd(b, a%b);
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        for (auto num: deck) {
            cnt[num]++;
            if (cnt[num] == 1) nums.push_back(num);
        }

        if (nums.size() == 0) return false;
        if (nums.size() == 1) {
            return cnt[nums[0]] >= 2;
        }

        int ans = cnt[nums[0]];
        for (int i = 1; i < nums.size(); i++) {
            ans = gcd(cnt[nums[i]], ans);
            if (ans <= 1) return false;
        }

        return true;
    }
};