class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0);
        unordered_map<string, int> m;

        for (auto update: updates) {
            if (!m[to_string(update[0])+"-"+to_string(update[1])]) {
                m[to_string(update[0])+"-"+to_string(update[1])] = update[2];
            } else {
                m[to_string(update[0])+"-"+to_string(update[1])] += update[2];
            }
        }

        for (auto p: m) {
            int i = 0;
            string str = "";
            for (i = 0; i < p.first.size(); i++) {
                if (p.first[i] == '-') {i++;break;}
                str += p.first[i];
            }
            int left = stoi(str);
            str="";
            for (; i<p.first.size(); i++) {
                str += p.first[i];
            }
            int right = stoi(str);

            for (int i = left; i <= right; i++) {
                ans[i] += p.second;
            }
        }

        return ans;
    }
};