class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> CP;
        for (int i = 0; i < capital.size(); i++) {
            CP.push_back(make_pair(capital[i], profits[i]));
        }
        sort(CP.begin(), CP.end());

        priority_queue<int> Q;

        int cnt = 0;
        int pointer = 0;
        while(cnt < k) {
            for (;pointer < capital.size() && CP[pointer].first <= w; pointer++) {
                Q.push(CP[pointer].second);
            }
            if (Q.empty()) break;
            w += Q.top();
            Q.pop();
            cnt++;
        }

        return w;
    }
};
