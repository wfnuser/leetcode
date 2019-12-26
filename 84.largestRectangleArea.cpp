class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        if (heights.size() == 0) return 0;
        vector<bool> visited(heights.size(), false);

        for (int i = 0; i<heights.size(); i++) {
            int sum = heights[i];
            int j = i - 1;
            if (visited[i]) continue;
            while(j>=0 && heights[j]>=heights[i]) {
                if (heights[i] == heights[j]) visited[j] = true; 
                sum += heights[i];
                j--;
            }
            j = i + 1;
            while(j<=heights.size()-1 && heights[j]>=heights[i]) {
                if (heights[i] == heights[j]) visited[j] = true; 
                sum += heights[i];
                j++;
            }
            ans = max(ans, sum);
        }

        return ans;
    }
};