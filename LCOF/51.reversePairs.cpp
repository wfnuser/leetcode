class Solution {
public:
    int ans = 0;

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int mid = ((long)left + right) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);

        int pl = left;
        int pr = mid+1;

        vector<int> tmp;
        int cnt = 0;
        while(true) {
            if (pl > mid) break;
            if (pr > right) break;
            if (nums[pl] <= nums[pr]) {
                tmp.push_back(nums[pl]);
                pl++;
                ans += cnt;
            } else {
                tmp.push_back(nums[pr]);
                pr++;
                cnt++;
            }
        }

        while(pl <= mid) {
            tmp.push_back(nums[pl++]);
            ans += cnt;
        }
        
        while(pr <= right) {
            tmp.push_back(nums[pr++]);
        }

        for (int i = 0; i < tmp.size(); i++) {
            nums[left + i] = tmp[i]; 
        }
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
};