class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> like;
        vector<string> ans;

        for (int i = 0; i < list1.size(); i++) {
            string res = list1[i];
            like[res] = i;
        }

        int target = INT_MAX;
        for (int i = 0; i < list2.size(); i++) {
            string res = list2[i];
            if (like.find(res) != like.end()) {
                target = min(target, i+like[res]);
            }
        }

        for (int i = 0; i < list2.size(); i++) {
            string res = list2[i];
            if (like.find(res) != like.end() && target == i+like[res]) {
                ans.push_back(res);
            }
        }

        return ans;
    }
};