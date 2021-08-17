class Solution {
public:
    int M = 1000000007;
    vector<vector<vector<int>>> mem;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        mem = vector<vector<vector<int>>>(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        return findPaths_(m, n, maxMove, startRow, startColumn);
    }


    long long findPaths_(int m, int n, int maxMove, int startRow, int startColumn) {
        if (startColumn < 0 || startColumn >= n || startRow < 0 || startRow >= m) return 1;
        if (maxMove == 0) {
            return 0;
        }
        if (mem[startRow][startColumn][maxMove] != -1) return mem[startRow][startColumn][maxMove];

        long long res = (findPaths_(m,n,maxMove-1,startRow-1,startColumn) + 
            findPaths_(m,n,maxMove-1,startRow+1,startColumn) + 
            findPaths_(m,n,maxMove-1,startRow,startColumn+1) + 
            findPaths_(m,n,maxMove-1,startRow,startColumn-1)) % M;
        mem[startRow][startColumn][maxMove] = res;
        return res;
    }
};
