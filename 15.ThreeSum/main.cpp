    void quick_sort(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int pivot = nums[l];
        int i = l;
        int j = r;

        while (i < j) {
            while(i<j && nums[j] >= pivot) j--;
            if(i<j) nums[i++] = nums[j];
            while(i<j && nums[i] < pivot) i++;
            if(i<j) nums[j--] = nums[i];
        }
        nums[i] = pivot;
        quick_sort(nums, l, i-1);
        quick_sort(nums, i+1, r);
    };

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        if (size < 3) return result;
        quick_sort(nums, 0, size-1);
        int pre = -100000;
        for (int i = 0; i < size - 2; i++) {
            int l = i+1;
            int r = size-1;
            int prel = -100000;
            int prer = -100000;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if (sum == 0) {
                    result.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l] == nums[l-1]) l++; 
                    while(l<r && nums[r] == nums[r+1]) r--; 
                } else if (sum > 0) {
                    r--;
                    while(l<r && nums[r] == nums[r+1]) r--; 
                } else {
                    l++;
                    while(l<r && nums[l] == nums[l-1]) l++; 

                }
            }
            while(nums[i] == nums[i+1] && i < size - 2) i++;
        }
        return result;
    };
};
