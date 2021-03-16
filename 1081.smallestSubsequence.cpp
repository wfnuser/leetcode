class Solution {
public:
    unordered_map<char, int> cnt;
    unordered_map<char, int> visit;
    
    string smallestSubsequence(string s) {
        for (auto c: s) {
            cnt[c]++;
        }

        string ans = "";
        stack<int> st;

        for (auto c: s) {
            if (visit[c]) {
                cnt[c]--;
                continue;
            }
            while(!st.empty()) {
                char top = st.top();
                if (c < top && cnt[top]>1) {
                    st.pop();
                    cnt[top]--;
                    visit[top]=0;
                } else {
                    break;
                }
            }
            if (!visit[c]){
                st.push(c);
                visit[c]=1;
            }
        }

        while(!st.empty()) {
            char top = st.top();
            st.pop();
            ans = top+ans;
        }

        return ans;
    }
};