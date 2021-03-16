class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> cnt;

        for (auto candy: candyType) {
            cnt[candy]++;
        }
        
        return min(cnt.size(), candyType.size()/2);
    }
};