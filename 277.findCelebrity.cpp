// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<vector<bool>> graph(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = knows(i, j);
            }
        }

        for (int j = 0; j < n; j++) {
            bool perhaps = true;
            for (int i = 0; i < n; i++) {
                if (!graph[i][j]) {
                    perhaps = false;
                    break;
                }
            }
            if (perhaps) {
                for (int i = 0; i < n; i++) {
                    if (i == j) continue;
                    if (graph[j][i]) {
                        perhaps = false;
                        break;
                    }
                }
            }
            if (perhaps) {
                return j;
            }
        }

        return -1;
    }
};