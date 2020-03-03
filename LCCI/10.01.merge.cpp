class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int a = 0;
        int b = 0;

        vector<int> ans;

        while(true) {
            if (a >= m) {
                while(b < n) {
                    ans.push_back(B[b++]);
                }
                break;
            }
            if (b >= n) {
                while(a < m) {
                    ans.push_back(A[a++]);
                }
                break;
            }
            if (A[a] < B[b]) {
                ans.push_back(A[a++]);
            } else {
                ans.push_back(B[b++]);
            }
        }

        A = ans;
    }
};