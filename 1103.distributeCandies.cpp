class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int i = 1;

        while(candies>0) {
            if (candies >= i) ans[(i-1)%num_people] += i;
            else ans[(i-1)%num_people] += candies;
            candies -= i;
            i++;
        }

        return ans;
    }
};