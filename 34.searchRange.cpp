class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int pos = -1; 
        vector<int> res(2,-1);

        if (nums.size() == 0) return res;

        if (nums.size() == 1)  {
            vector<int> r(2,0);
            if (target == nums[0]) return r;
            return res;
        }

        while(l<r) {
            int mid = (l+r)/2;
            if (nums[mid]==target) {
                pos = mid;
                break;
            }
            if (nums[mid] < target) {
                l = mid+1;
            }
            if (nums[mid] > target) {
                r = mid;
            }
        }
        if (nums[l] == target) pos = l;
        if (pos == -1) return res;

        l=0; 
        r=pos;
        while(l<r) {
            cout << l << " " << r << endl;
            int mid = (l+r)/2;
            if (nums[mid] == target) {
                r = mid;
            }
            if (nums[mid]<target) {
                l = mid+1;
            }
        }
        res[0] = r;
        l=pos;
        r= nums.size()-1;
        while(l<r) {
            cout << l << " " << r << endl;
            int mid = (l+r) / 2;
            if (nums[mid] == target) {
                l = mid;
            }
            if(l<r && nums[l+1]==target) {
                l = l+1;
            }
            if (l<r && nums[l+1]>target) {
                break;
            }
            if (nums[mid]>target) {
                r = mid;
            }
        }
        res[1] = l;

        return res;
    }
};