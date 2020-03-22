class Solution {
public:
    
    unordered_map<int, int> cnt;
    
    void dfs(string s) {
        if (s.size() == 10) {
            int last = -1;
            int ans = 0;
            for (int i = 0; i < 10; i++) {
                if (s[i]-'0') {
                    last = i;
                } else {
                    if (i - last >= 4) {
                        if (i == 3 || i == 5 || i == 7 || i == 9) {
                            last = i - 4 + 1;
                        } else {
                            last = i;
                            ans++;
                        }
                    }
                }
            }
            
            int num = 0;
            for (int i = 0; i < 10; i++) {
                if (s[i] == '1') {
                    num |= (1 << i);
                }
            }
            cnt[num] = ans;
        } else {
            string s0 = s + "0";
            dfs(s0);
            string s1 = s + "1";
            dfs(s1);
        }
    }
    
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        dfs("");

        unordered_map<int, int> seats;
        for (auto seat: reservedSeats) {
            seats[seat[0]-1] |= (1 << (seat[1] - 1)) ;
        }
        
        int ans = 0;
        int lines = 0;
        for (auto pair: seats) {
            ans += cnt[pair.second];
            lines++;
        }
        
        ans += (n - lines)*2;
        
        
        return ans;
    }
};