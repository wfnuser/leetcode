class Solution {
public:
    vector<int> used = vector<int>(20, 0);

    int countArrangement(int n) {
        return dfs(1, n);
    }

    int dfs(int index, int n) {
        if (index > n) return 1;

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            if (i % index != 0 && index % i != 0) continue;
            used[i] = 1;
            sum += dfs(index+1, n);
            used[i] = 0;
        }

        return sum;
    }
};
