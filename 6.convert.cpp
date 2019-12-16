class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<int>> m(numRows, vector<int>());
        if (numRows == 1) return s;

        int pos = 0;
        int row = 0;
        int size = s.size();
        int inc = 1;
        string ans = "";

        while(true) {
            if (pos >= size) break;
            if (row >= numRows) {
                row -= 2;
                inc = -1;
            }
            if (row < 0) {
                row += 2;
                inc = 1;
            }
            m[row].push_back(s[pos]);
            row += inc;
            pos++;
        }

        for (int i = 0; i < numRows; i++) {
            for (auto c : m[i]) {
                ans+=c;
            }
        }

        return ans;
    }
};