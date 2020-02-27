class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,int> mp;
        for (const auto& b: bank) mp[b]=0;
        if (mp.count(end)==0)return -1;

        queue<string> q1;
        q1.push(start);

        queue<string> q2;
        q2.push(end);

        char gene[4] = {'A', 'T', 'G', 'C'};

        // 学习了大神的双向遍历模板; 太强了!
        int step = 0;
        for (mp[start]=1, mp[end]=2; q1.size()&&q2.size(); step++) {
            int first = q1.size() < q2.size();
            int dir = first ? 1 : 2;
            queue<string>& q = first ? q1 : q2;

            for(int n=q.size();n--;q.pop()){
                string top = q.front();
                mp[top] |= dir;

                if (mp[top] == 3) return step;
                
                // 遍历从当前字符串所能生成的所有字符串
                for (int i = 0; i < top.size(); i++) {
                    for (int j = 0; j < 4; j++) {
                        string s = top;
                        if (s[i] == gene[j]) continue;
                        s[i] = gene[j];
                        // 不存在或者已被遍历过 则跳过
                        if (mp.count(s) == 0 || mp[s]&dir) continue;
                        mp[s] |= dir;
                        q.push(s);
                    }
                }
            }
        }

        return -1;   
    }
};