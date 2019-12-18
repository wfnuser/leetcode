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
    int threeSumClosest(vector<int>& nums, int target) {
        quick_sort(nums, 0, nums.size() - 1);
        int delta = INT_MAX;
        int ans = 0;

        for (int i = 0; i < nums.size()-2; i++) {
            int first = nums[i];
            int l=i+1;
            int r=nums.size()-1;
            while(l<r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum==target) {
                    return target;
                } else if (sum>target) {
                    if (delta>(sum-target)) {
                        ans = sum;
                        delta = sum - target;
                    }
                    r--;
                } else {
                    if (delta>(target-sum)) {
                        ans = sum;
                        delta = target - sum;
                    }
                    l++;
                }
            } 
        }

        return ans;
    }
};