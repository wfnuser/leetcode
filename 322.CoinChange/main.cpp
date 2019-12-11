class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int options = coins.size();
        vector<int> nums(amount+1, -1);
        nums[0] = 0;
        for (int a = 1; a <= amount; a++) {
            for (int i = 0; i < options; i++) {
                if (coins[i] <= a) {
                    if (nums[a-coins[i]] != -1 ) {
                        if (nums[a] == -1) nums[a] = nums[a-coins[i]]+1;
                        else if (nums[a-coins[i]]+1 < nums[a]) nums[a] = nums[a-coins[i]]+1;
                    }
                }
            }
        }

        return nums[amount];
    }
};
