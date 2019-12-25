class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        int num = t.size();
        int len = INT_MAX;
        int start = 0;
        int left = 0;

        for(auto val: t) hash[val]++;

        for(int i =0; i < s.size(); i++) {
            if(hash[s[i]]-- >0) num--;
            while(num==0) {
                if (len>(i-left+1)) {
                    len = i - left + 1;
                    start = left;
                }
                if (hash[s[left]] == 0) {
                    num++;
                }
                hash[s[left]]++;
                left++;
            }
        }

        if (len == INT_MAX) return "";
        return s.substr(start, len);
    }
};