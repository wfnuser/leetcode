class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        return v1[0]>v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);

        vector<vector<int>> ans;
            
        for (int i = 0; i < people.size(); i++) {
            ans.insert(ans.begin()+people[i][1], people[i]);
        }

        return ans;
    }

};