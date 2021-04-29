class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len=stones.size();
        vector<vector<bool>>dp(len,vector<bool>(len+1,false));//dp的长度之所以定义为len+1是因为第0块石头为0步，就算每跳一次加一步，最多也只能跳len步。
        dp[0][0]=true;
        for(int i=1;i<len;i++){
            for(int j=0;j<i;j++){
                int k=stones[i]-stones[j];
                if(k<len+1&&k<=stones[j]+1){
                    dp[i][k]=dp[j][k-1]||dp[j][k]||dp[j][k+1];
                    if(i==len-1&&dp[i][k]==true) return true;
                }
            }
        }
        return false;
    }
};