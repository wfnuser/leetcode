class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> before;
        vector<int> after;
        vector<int> b;
        if (a.size() == 0) return b;
        
        int tmp = 1;
        int tmp2 = 1;
        for (int i = 0; i < a.size(); i++) {            
            tmp *= a[i];
            before.push_back(tmp);
            tmp2 *= a[a.size()-1-i];
            after.push_back(tmp2);
        }
        reverse(after.begin(), after.end());

        b.push_back(after[1]);
        for (int i = 1; i < a.size()-1; i++) {
            b.push_back(before[i-1]*after[i+1]);
        }
        if (a.size() >= 2) {
            b.push_back(before[a.size()-2]);
        }

        return b;
    }
};