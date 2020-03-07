class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        stack<int> S;
        int n = pushed.size();
        if (n != popped.size()) return false;
        while(i<n && j < n) {
            while(i < n && pushed[i] != popped[j]) {
                S.push(pushed[i]);
                i++;
            }
            if (i >= n) break;
            S.push(pushed[i]);
            while(!S.empty() && S.top() == popped[j]) {
                j++;
                S.pop();
            }
            i++;
        }
        if (j < pushed.size()) return false;
        return true;
    }
};