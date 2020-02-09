class Solution {
public:
    stack<string> ans;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;

    void dfs(string node) {
        if (graph.find(node) == graph.end()) {
            ans.push(node);
            return;
        }

        while(!graph[node].empty()) {
            string next = graph[node].top();
            graph[node].pop();
            dfs(next);
        }
        
        ans.push(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket: tickets) {
            string start = ticket[0];
            string end = ticket[1];
            graph[start].push(end);
        }
        dfs("JFK");
        
        vector<string> res;
        while(!ans.empty()) {
            res.push_back(ans.top());
            ans.pop();
        }

        return res;
    }
};