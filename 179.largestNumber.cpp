class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string sa = to_string(a);
            string sb = to_string(b);

            return sa + sb > sb + sa;
        });
        string ans = "";
        for (auto num : nums) {
            ans = ans + to_string(num);
            if (ans == "0") ans = "";
        }
        if (ans == "") return "0";
        return ans;
    }
};