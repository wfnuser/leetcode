class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> clusters;
        int cnt[26] = {0};
        for(int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            memset(cnt, 0, sizeof(cnt));
            for (char ch:str) {
                cnt[ch-'a']++;
            }
            string key = "";
            for (auto num:cnt) {
                key += "#" + to_string(num);
            }
            clusters[key].push_back(str);
        }



        map<string, vector<string>>::iterator iter;
        iter = clusters.begin();
        while(iter != clusters.end()) {
            ans.push_back(iter->second);
            iter++;
        }

        return ans;
    }
        
};
