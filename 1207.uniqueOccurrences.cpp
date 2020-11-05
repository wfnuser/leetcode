class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;

        for (auto num: arr) {
            cnt[num]++;
        }

        unordered_map<int, int> set;
        for (auto pair: cnt) {
            if(set[pair.second] > 0) return false;
            set[pair.second]++;
        }

        return true;
    }
};