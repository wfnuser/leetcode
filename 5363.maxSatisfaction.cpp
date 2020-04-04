class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<int> neg;
        vector<int> pos;
        
        int ans = 0;
        int sum = 0;
        
        for (auto e: satisfaction) {
            if (e >= 0) {
                pos.push_back(e);
                sum += e;
            } else neg.push_back(e);
        }
        
        sort(pos.begin(), pos.end());
        
        for (int i = 0; i < pos.size(); i++) {
            ans += pos[i]*(i+1);
        }
        
        sort(neg.begin(), neg.end());
        
        for (int i = neg.size()-1; i >= 0; i--) {
            if (sum + neg[i] >= 0) {
                sum += neg[i];
                ans += sum;
            }
        }
        
        return ans;
    }
};