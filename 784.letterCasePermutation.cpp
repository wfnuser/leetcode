class Solution {
public:

    vector<string> ans;

    char convert(char c) {
        if (c >= 'a' && c <= 'z') c = c - ('a' - 'A');
        else c = c + ('a' - 'A');

        return c;
    }

    void dfs(int pos, string& S, vector<int>& chars) {
        if (pos >= chars.size()) {
            ans.push_back(S);
            return;
        }

            dfs(pos+1, S, chars);
            char org = S[chars[pos]];
            S[chars[pos]] = convert(S[chars[pos]]);
            dfs(pos+1, S, chars);
            S[chars[pos]] = org;
    }

    vector<string> letterCasePermutation(string S) {
        vector<int> chars;
        for (int i = 0; i < S.size(); i++) {
            if ((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z')) chars.push_back(i);
        }
        cout << chars.size() << endl; 

        dfs(0, S, chars);

        return ans;
    }
};