class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> v;
        unordered_map<int, int> m;
        int i = 0;
        for (i = 0; i < nums.size(); i++) {
            if (v.size()>=3) {break;}
            if (m[nums[i]] > 0) continue;
            m[nums[i]]++;
            v.push_back(nums[i]);
        }

        if (v.size() == 1) return v[0];
        if (v.size() == 2) return max(v[0], v[1]);

        for (; i<nums.size(); i++) {
            int flag = 0;
            int min = -1;
            for (int j = 0; j < 3; j++) {
                if (nums[i] == v[j]) {
                    flag = 0;
                    break;
                }
                if (nums[i] > v[j]) {
                    flag = 1;
                }
                if (min >= 0) {
                    if (v[j] < v[min]) min = j;
                } else {
                    min = 0;
                }
            }        
            if (flag) v[min] = nums[i];
        }

        int min = 0;
        for (int i = 0; i < 3; i++) {
            if (v[min]>=v[i]) min = i;
        }

        return v[min];
    }
};