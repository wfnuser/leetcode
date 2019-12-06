class Solution {
public:
    int longestValidParentheses(string s) {
        int i = 1;
        int size = s.length();
        vector<int> bracketPos(size, -1);
        queue<int> q;
        int ans = 0;

        while (i<=size-1) {
            if (s[i] == ')' && s[i-1]=='(') {
                q.push(i);
                bracketPos[i] = i-1;
                bracketPos[i-1] = i;
                ans = 2;
            }
            i++;
        }
        
        while(!q.empty()) {
            int right = q.front();
            int left = bracketPos[right];

            cout << "left is : " << left << endl;
            cout << "right is : " << right << endl;        

            while(left >= 1 && right <= size - 1) {
                
                if (bracketPos[left-1] != -1) {
                    left = bracketPos[left-1];
                    bracketPos[right] = left;
                    bracketPos[left] = right;
                    if (right - left + 1 > ans) ans = right - left + 1;
                    continue;
                }
                if (right <= size - 2 && s[left-1] == '(' && s[right+1] == ')') {
                    left--;
                    right++;
                    bracketPos[left] = right;
                    bracketPos[right] = left;
                    if (right - left + 1 > ans) ans = right - left + 1;
                    continue;
                }
                break;
            }
            q.pop();
        }

        cout << ans;
        return ans;
    }
};
