class Solution {
public:
    string sortString(string s) {
        map<char, int> cnt;
        
        for (auto c: s) {
            cnt[c]++;
        }
        string ans = "";
        
        while (true) { 
            bool flag = false;
            string forward = "";
            for (auto m: cnt) {
                if (m.second <= 0) continue;
                flag = true;
                cnt[m.first]--;
                
                forward += m.first;
            }
            if (!flag) break;
            ans += forward;
            
            string backward = "";
            flag = false;
            for (auto m: cnt) {
                if (m.second <= 0) continue;
                flag = true;
                cnt[m.first]--;
                
                backward = m.first + backward;
            }
            if(!flag) break;
            ans += backward;
        }
        
        return ans;
    }
};