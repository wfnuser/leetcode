// 此题为2020 阿里巴巴全球数学竞赛的题目
// 题目意思是说在3*4的方格里种树，不能三棵树并排，并列或处于同一斜线
// 问最多种多少棵树，种这么多棵树的方法一共多少种

#include<iostream>
#include<cstdio>
#include<vector>

using namespace	std;

class Solution {
public:

    int cnt = 0;
    int cnt2 = 0;
	vector<vector<int>> grid = vector<vector<int>>(3, vector<int>(4, 0));
    int maxTrees = 0;

    bool check(int i, int j) {
        int sum1 = 0;
        for (int row = 0; row < 3; row++) {
            sum1 += grid[row][j];
        }
        if (sum1 >= 3) return false;

        int sum2 = 0;
        for (int col = 0; col < 3; col++) sum2 += grid[i][col];
        if (sum2 >= 3) return false;
        sum2 = 0;
        for (int col = 1; col < 4; col++) sum2 += grid[i][col];
        if (sum2 >= 3) return false;

        sum2 = 0;
        for (int l = 0; l < 3; l++) {
            sum2 += grid[l][l];
        }
        if (sum2 >= 3) return false;

        sum2 = 0;
        for (int l = 0; l < 3; l++) {
            sum2 += grid[l][l+1];
        }
        if (sum2 >= 3) return false;

        sum2 = 0;
        for (int l = 0; l < 3; l++) {
            sum2 += grid[l][2-l];
        }
        if (sum2 >= 3) return false;

        sum2 = 0;
        for (int l = 0; l < 3; l++) {
            sum2 += grid[l][3-l];
        }
        if (sum2 >= 3) return false;

        return true;
    }

    void dfs(int step, int trees) {
        if (step >= 12) {
            cnt++;
            if (trees == 7) {
                
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 4; j++) {
                        cout << grid[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
                
                cnt2++;
            }


            maxTrees = max(maxTrees, trees);
            return;
        }

        int i = step / 4;
        int j = step % 4;

        grid[i][j] = 1;
        if (check(i, j)) dfs(step+1, trees+1);
        
        grid[i][j] = 0;
        dfs(step+1, trees);
    }

    int solve() {
        dfs(0, 0);
        cout << maxTrees << " " << cnt << " " << cnt2;
        return 0;
    }
};

int main()
{
    Solution s;
    s.solve();
}
