class Solution {
public:
    bool flag = false;
    
    void dfs(vector<int>& target, long sum) {
        if (flag) return;
        if (sum == target.size()) {flag = true;return;}
        for (int i = 0; i < target.size(); i++) {
            if ((long)2*target[i] <= sum) continue;
            int origin = target[i];
            target[i] = 2*target[i] - sum;
            dfs(target, sum-origin+target[i]);
            target[i] = origin;
        }
    }
    
    bool isPossible(vector<int>& target) {
        long sum = 0;
        for (auto num: target) {
            if (sum >= (long)2*INT_MAX-num) {return false;}
            sum += num;
        }
        dfs(target, sum);
        
        return flag;
    }
};