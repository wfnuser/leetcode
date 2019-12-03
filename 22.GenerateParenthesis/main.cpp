class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {

        queue<string> q;
        queue<int> s;
        queue<int> l;
        q.push("");
        s.push(0);
        l.push(0);
        while(!q.empty()) {
            string path = q.front();
            q.pop();
            if (path.length() == 2*n) {
                ans.push_back(path);
                continue;
            }
            int stack = s.front();
            s.pop();
            int left = l.front();
            l.pop();


            if (stack > 0) {
                q.push(path+')');
                s.push(stack-1);
                l.push(left);
            }
            if (left < n) {
                q.push(path+'(');
                s.push(stack+1);
                l.push(left+1);
            }
        }

       
        return ans;
    }

};
