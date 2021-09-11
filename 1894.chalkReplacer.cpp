class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        int n = chalk.size();

        for (auto c: chalk) sum += c;
        k %= sum;

        for (int i = 0; i < n; i++) {
            k -= chalk[i];
            if (k < 0) return i;
        }

        return 0;
    }
};
