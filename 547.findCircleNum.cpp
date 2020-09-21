class Solution {
public:
    int parent[250] = {0};

    int find(int i) {
        while(parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return parent[i];
    }

    void uni(int i, int j) {
        int pi = find(i);
        int pj = find(j);

        if (pi != pj) {
            parent[pi] = pj;
        }
    }


    int findCircleNum(vector<vector<int>>& M) {
        int m = M.size();

        for (int i = 0; i < m; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < m; i++) {
            for (int j = i+1; j < m; j++) {
                if (M[i][j]) {
                    uni(i, j);
                }
            } 
        }

        unordered_map<int, int> cnt;
        for (int i = 0; i < m; i++) {
            cnt[find(i)]++;
        }

        return cnt.size();
    }
};