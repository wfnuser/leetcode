class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        char last = 'A';
        int cnt = 0;
        int start = 0;
        vector<vector<int>> ans;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == last) {
                cnt++;
            } else {
                if (cnt>=3) {
                    vector<int> range(2, 0);
                    range[0] = start;
                    range[1] = i - 1;
                    ans.push_back(range);
                }
                start = i;
                last = c;
                cnt = 1;
            }
        }

        if (cnt>=3) {
            vector<int> range(2, 0);
            range[0] = start;
            range[1] = s.size() - 1;
            ans.push_back(range);
        }

        return ans;
    }
};