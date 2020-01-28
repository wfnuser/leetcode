class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        double mid = -(0.0+b)/2/a;
        vector<int> ans;

        if (a == 0) {
            for (auto num: nums) {
                ans.push_back(b*num+c);
            }
            if (b < 0) {
                for (int i = 0; i < ans.size(); i++) {
                    int j = ans.size() - i - 1;
                    if (j <= i) break;
                    int tmp = ans[i];
                    ans[i] = ans[j];
                    ans[j] = tmp;
                }
            }
            return ans;
        }

        int i = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] >= mid) break;
        }

        if (i == 0) {
            for (auto num: nums) {
                ans.push_back(a*num*num + b*num +c);
            }
            if (a < 0) {
                for (int i = 0; i < ans.size(); i++) {
                    int j = ans.size() - i - 1;
                    if (j <= i) break;
                    int tmp = ans[i];
                    ans[i] = ans[j];
                    ans[j] = tmp;
                }
            }
            return ans;
        }
        if (i == nums.size()) {
            for (auto num: nums) {
                ans.push_back(a*num*num + b*num +c);
            }
            if (a > 0) {
                for (int i = 0; i < ans.size(); i++) {
                    int j = ans.size() - i - 1;
                    if (j <= i) break;
                    int tmp = ans[i];
                    ans[i] = ans[j];
                    ans[j] = tmp;
                }
            }
            return ans;
        }

        int j = i - 1;
        while(true) {
            if (j >= 0 && i < nums.size()) {
                if (nums[i] - mid < mid - nums[j]) {
                    ans.push_back(a*nums[i]*nums[i] + b*nums[i] +c);
                    i++;
                } else {
                    ans.push_back(a*nums[j]*nums[j] + b*nums[j] +c);
                    j--;
                }
            } else {
                if (j < 0 && i >= nums.size()) break;
                if (j < 0) {
                    ans.push_back(a*nums[i]*nums[i] + b*nums[i] +c);
                    i++;
                } else {
                    ans.push_back(a*nums[j]*nums[j] + b*nums[j] +c);
                    j--;
                }
            }
        }

        if (a < 0) {
            for (int i = 0; i < ans.size(); i++) {
                int j = ans.size() - i - 1;
                if (j <= i) break;
                int tmp = ans[i];
                ans[i] = ans[j];
                ans[j] = tmp;
            }
        }

        return ans;
    }
};