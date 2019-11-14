#include<iostream>
#include<cstdio>
#include<vector>

using namespace	std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		vector<int> increments;
		int sum = 0;
		int maxIncrement = 0;
		for (int i = 0; i < customers.size(); i++) {
			increments.push_back(customers[i] * grumpy[i]);
			sum += customers[i] * (1-grumpy[i]);
		}
		for (int i = 0; i < customers.size() - X + 1; i++) {
			int sum = 0;
			for (int j = i; j < i + X; j++) {
				sum += increments[j];
			}
			if (sum > maxIncrement) {
				maxIncrement = sum;
			}
		}
		return sum + maxIncrement;
    }
};

int main()
{
    Solution s;
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int X = 3;
    int ans = s.maxSatisfied(customers, grumpy, X);
    cout << ans;
}
