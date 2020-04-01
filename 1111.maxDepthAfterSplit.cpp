class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<int> S;
        vector<int> ans;
        for (auto c: seq) {
            if (c == '(') {
                ans.push_back(S.size());
                S.push(0);
            } else {
                if (S.empty()) {
                    ans.push_back(0);
                    continue;
                }
                if (S.top() == 0) {
                    S.pop();
                    ans.push_back(S.size());
                } else {
                    ans.push_back(S.size());
                    S.push(1);
                }
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] % 2 == 0) {
                ans[i] = 0;
            } else {
                ans[i] = 1;
            } 
        }

        return ans;
    }
};