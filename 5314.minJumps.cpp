class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> shortcut;
        unordered_map<int, int> visited;
        unordered_map<int, int> visitedShortCut;
        for (int i = 0; i < arr.size(); i++) {
            shortcut[arr[i]].push_back(i);
        }
        queue<pair<int, int>> Q;
        Q.push(make_pair(0, 0));
        int step = 0;
        
        while(!Q.empty()) {
            pair<int, int> p = Q.front();
            Q.pop();
            visited[p.first] = 1;
            if (p.first == arr.size() - 1) {
                return p.second;
            } else {
                int tmp = p.first - 1;
                if (!visited[tmp] && tmp>=0) Q.push(make_pair(tmp, p.second+1));
                tmp = p.first + 1;
                if (!visited[tmp] && tmp<arr.size()) Q.push(make_pair(tmp, p.second+1));
                if (!visitedShortCut[arr[p.first]]) {
                    for (auto e: shortcut[arr[p.first]]) {
                        if (!visited[e]) {
                            Q.push(make_pair(e, p.second+1));
                        }
                    }
                    visitedShortCut[arr[p.first]] = 1;
                }
                
            }
        }
        
        return 0;
    }
};