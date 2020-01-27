class Solution {
public:
    unordered_map<string, vector<string>> m;

    vector<vector<string>> groupStrings(vector<string>& strings) {
        
        vector<vector<string>> ans;
        for (auto s: strings) {
            char pre = s[0];
            string key = "";
            for (auto c: s) {
                key = key + to_string('a' + (c + 26 - pre) % 26 );
                pre = c; 
            }
            m[key].push_back(s);
        }

        for (auto pair: m) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};