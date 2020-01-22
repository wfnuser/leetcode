class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();

        int sum = (size+1)*size/2;
        int act = 0;
        for (auto num: nums) {
            act += num;
        }

        return sum - act;
    }
};
