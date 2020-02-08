class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(org.size()+1, 0);
        if (seqs.size() == 0) return false;
        bool noNumber = true;
        for(int j = 0; j < seqs.size(); j++) {
            vector<int> seq = seqs[j];
            if (seq.size() == 0) continue;
            noNumber = false;
            if (seq[0]<=0 || seq[0]>org.size()) return false;
            for(int i = 0; i < seq.size()-1; i++) {
                if (seq[i+1]<=0 || seq[i+1]>org.size()) return false;
                indegree[seq[i+1]]++;
                graph[seq[i]].push_back(seq[i+1]);
            }
        }
        if (noNumber) return false;

        int start = -1;
        for (int i = 1; i < org.size()+1; i++) {
            if (indegree[i] == 0) {
                if (start != -1) return false;
                start = i;
            }
        }
        if (start == -1) return false;

        queue<int> Q;
        Q.push(start);
        int nodes = 0;
        while(!Q.empty()) {
            int node = Q.front();
            nodes++;
            Q.pop();
            int cnt = 0;
            for (auto next: graph[node]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    if (cnt!=0) return false;
                    Q.push(next);
                    cnt++;
                }
            }
        }

        return nodes == org.size();
    }
};