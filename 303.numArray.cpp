class NumArray {
public:
    vector<int> partialSum;

    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            partialSum.push_back(sum);
        }    
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return partialSum[j];
        return partialSum[j] - partialSum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */