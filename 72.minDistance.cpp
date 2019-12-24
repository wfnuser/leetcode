class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        
        if (l1 > l2) return minDistance(word2, word1);
        if (l1 == 0) return l2;

        vector<vector<int>> dp(l1, vector<int>(l2, 0));

        if (word1[0] == word2[0]) dp[0][0] =0;
        else dp[0][0] = 1;

        for (int i = 1; i < l1; i++) {
            if (word1[i] == word2[0]) dp[i][0] = i;
            else dp[i][0] = dp[i-1][0] + 1;
        }
        for (int j = 1; j < l2; j++) {
            if (word1[0] == word2[j]) dp[0][j] = j;
            else dp[0][j] = dp[0][j-1] + 1;
        }

        for (int i = 1; i < l1; i++) {
            for (int j = 1; j < l2; j++) {
                int min;
                min = dp[i-1][j] + 1;
                if (min>dp[i][j-1]+1) min = dp[i][j-1]+1;
                if (word1[i] == word2[j] && min > dp[i-1][j-1]) min = dp[i-1][j-1];
                if (word1[i] != word2[j] && min > dp[i-1][j-1] + 1) min = dp[i-1][j-1] + 1;
                dp[i][j] = min; 
            }
        }

        return dp[l1-1][l2-1];
    }
};

