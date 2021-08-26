class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        vector<vector<int>> dp(n,vector<int>(k,0));
        int min_1 = INT_MAX, min_2 = INT_MAX, min_1_i = 0;
        for(int j=0;j<k;j++)
        {
            dp[0][j] = costs[0][j];
            if(min_1>=dp[0][j])
            {
                min_2 = min_1;
                min_1 = dp[0][j];
                min_1_i = j;
            }
            else if(min_2>=dp[0][j])
            {
                min_2 = dp[0][j];
            }
        }
        for(int i=1;i<n;i++)
        {
            int t_min_1 = INT_MAX, t_min_2 = INT_MAX, t_min_1_i = 0;
            for(int j=0;j<k;j++)
            {
                if(j==min_1_i)
                    dp[i][j] = costs[i][j] + min_2;
                else
                    dp[i][j] = costs[i][j] + min_1;
                
                if(t_min_1>=dp[i][j])
                {
                    t_min_2 = t_min_1;
                    t_min_1 = dp[i][j];
                    t_min_1_i = j;
                }
                else if(t_min_2>=dp[i][j])
                {
                    t_min_2 = dp[i][j];
                }
            }
            min_1 = t_min_1;
            min_1_i = t_min_1_i;
            min_2 = t_min_2;
        }
        return min_1;
    }
};
