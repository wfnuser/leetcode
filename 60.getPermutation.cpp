class Solution {
public:
    string getPermutation(int n, int k) {

        int order[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        string ans = "";

        vector<int> choice(9, 0);
        for (int i=0; i<9; i++) {
            choice[i] = i+1;
        }

        k = k - 1;
        for (int i = n-1; i>=1; i--) {
            int pos = k / order[i];
            k = k % order[i];
            ans += to_string(choice[pos]);
            choice.erase(choice.begin()+pos);
        }
        ans += to_string(choice[0]);

        return ans;
    }
};