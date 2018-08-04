class Solution {
public:
    int getMoneyAmount(int n) {
        int **arr;
        arr = (int**)malloc(sizeof(int*)*(n+1));
        for (int i=0; i<=n; i++) {
            arr[i] = (int*)malloc(sizeof(int)*(n+1));
        }
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                arr[i][j] = 0;
            }
        }
        
        return cal(1, n, arr);
    }
    
    int cal(int s, int e, int** arr) {
        if (s >= e) {
            return 0;
        }
        if (arr[s][e] > 0) return arr[s][e];
        
        int res = 2147483647;
        for (int i=s; i<=e; i++) {
            int t = max(cal(s, i-1, arr), cal(i+1, e, arr))+i;
            res = min(res, t);
        }
        arr[s][e] = res;
        
        return res;
    }
};
