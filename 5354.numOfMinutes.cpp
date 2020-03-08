class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> emps(n, vector<int>());
        
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] == -1) continue;
            emps[manager[i]].push_back(i);
        }
        
        queue<pair<int, int>> Q;
        Q.push(make_pair(headID, 0));
        
        int time = 0;
        while(!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> p = Q.front();
                int manager = p.first;
                int cost = p.second;
                Q.pop();
                
                if (emps[manager].size() == 0) {
                    time = max(time, cost);
                    continue;
                }
                
                for (auto emp: emps[manager]) {
                    Q.push(make_pair(emp, cost+informTime[manager]));
                }
            }
        }
        
        return time;
    }
};