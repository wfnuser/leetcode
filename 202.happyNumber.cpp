class Solution {
public:
    int cal(int n) {
        int ans = 0;
        while(n) {
            ans += (n%10)*(n%10);
            n = n / 10;
        }
        return ans;
    }

    bool isHappy(int n) {
        unordered_set<int> lookup;

        while(n != 1) {
            if (lookup.find(n) != lookup.end()) {
                return false;
            }
            lookup.insert(n);
            n = cal(n);
        }

        return true;
    }
};