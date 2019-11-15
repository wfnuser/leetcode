class Solution {
private:
    unordered_map<int, vector<int>> map;

public:
    int search_solution(int index, vector<int> arr, int l, int r) {
        if (l == r) {
            return abs(arr[l] - index);
        }
        if (l == r - 1) {
            return abs(arr[l] - index) < abs(arr[r] - index) ? abs(arr[l] - index) : abs(arr[r] - index);
        }
        int mid = (l + r) / 2;
        if (arr[mid] == index) {
            return 0;
        } else {
            if (arr[mid] < index) {
                return search_solution(index, arr, mid, r);
            } else {
                return search_solution(index, arr, l, mid);
            }
        }
    }

    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        map[0] = vector<int>(0);
        map[1] = vector<int>(0);
        map[2] = vector<int>(0);
        vector<int> ans;

        // pre processing
        for (int i = 0; i < colors.size(); i++) {
            map[colors[i]-1].push_back(i);
        }

        for (int i = 0; i < queries.size(); i++) {
            int index = queries[i][0];
            int color = queries[i][1] - 1;

            if (map[color].size() == 0 || map[color].size() == 1 && map[color][0] == index) {
                ans.push_back(-1);
            } else {
                ans.push_back(search_solution(index, map[color], 0, map[color].size()-1));
            }
        }

        return ans;
    }
};
