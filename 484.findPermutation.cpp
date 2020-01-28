class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> ans;
        int cnt = 0;
        int begin = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I') {
                while(cnt) {
                    ans.push_back(begin+cnt);
                    cnt--;
                }
                ans.push_back(begin);
                begin = i + 2;
            } else {
                cnt++;
            }
        }

        while(cnt) {
            ans.push_back(begin+cnt);
            cnt--;
        }
        ans.push_back(begin);

        return ans;
    }
};