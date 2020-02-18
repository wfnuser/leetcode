class Solution {
public:

    vector<string> helper(int n) {
        if (n == 1) {
            return vector<string>{"0", "1", "8"};
        }
        if (n == 2) {
            return vector<string>{"11", "69", "88", "96", "00"};
        }
        vector<string> subs = helper(n-2);
        vector<string> ans;

        for (auto sub: subs) {
            ans.push_back("0"+sub+"0");
            ans.push_back("1"+sub+"1");
            ans.push_back("6"+sub+"9");
            ans.push_back("9"+sub+"6");
            ans.push_back("8"+sub+"8");
        }

        return ans;
    }

    vector<string> findStrobogrammatic(int n) {
        if (n == 1) {
            return vector<string>{"0", "1", "8"};
        }
        if (n == 2) {
            return vector<string>{"11", "69", "88", "96"};
        }

        vector<string> subs = helper(n-2);
        vector<string> ans;
        for (auto sub: subs) {
            ans.push_back("1"+sub+"1");
            ans.push_back("6"+sub+"9");
            ans.push_back("9"+sub+"6");
            ans.push_back("8"+sub+"8");
        }

        return ans;
    }
};