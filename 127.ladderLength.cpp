class Solution {
public:

    inline int calDistance(string s1, string s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) cnt++;
        }
        return cnt;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> visited;
        for (int i = 0; i < wordList.size()-1; i++) {
            for (int j = i+1; j < wordList.size(); j++) {
                if (calDistance(wordList[i], wordList[j]) == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int target = -1;
        for (int i = 0; i < wordList.size(); i++) {
            if (1==calDistance(beginWord, wordList[i])) {
                graph[-1].push_back(i);
            }
            if (endWord == wordList[i]) target = i;
        }
        if (target == -1) return 0;

        queue<pair<int, int>> Q;
        Q.push(make_pair(-1, 1));

        while (!Q.empty()) {
            pair<int, int> node = Q.front();
            Q.pop();
            if (node.first == target) {
                return node.second;
            }
            visited[node.first] = 1;

            for (auto next: graph[node.first]) {
                if (visited[next]) continue;
                Q.push(make_pair(next, node.second+1));
            }
        }

        return 0;
    }
};