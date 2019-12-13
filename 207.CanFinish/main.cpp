class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int size = prerequisites.size();
        vector<int> root(numCourses, 1);
        vector<int> visited(numCourses, 0);
        vector<vector<int>> pre(numCourses, vector<int>());
        vector<vector<int>> next(numCourses, vector<int>());
        queue<int> q;

        for (int i = 0; i<size; i++) {
            root[prerequisites[i][1]] = 0; 
            pre[prerequisites[i][1]].push_back(prerequisites[i][0]);
            next[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i<numCourses; i++) {
            if (root[i]) q.push(i);
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = 1;
            for(auto n : next[cur]) {
                // 所有前置课程已修
                bool flag = true;
                for (auto p: pre[n]) {
                    if (!visited[p]) {
                        // 有课未修
                        flag = false;
                        break;
                    }
                }
                if (flag) q.push(n);
            }
        }

        for (int i = 0; i<numCourses; i++) {
            if (!visited[i]) return false;
        }

        return true;
    }
};
