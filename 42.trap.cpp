class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int, int>> bar;
        int i = 0;
        while(i < height.size() && height[i] == 0) i++;
        if (i == height.size()) return 0;

        bar.push(make_pair(i,height[i]));
        i++;
        int sum = 0;
        while(i < height.size()) {
            int curHeight = height[i];

            while(!bar.empty()) {
                pair<int, int> last = bar.top();
                int lastHeight = last.second;
                int lastIndex = last.first;
                if (curHeight < lastHeight) break;
                bar.pop();
                if (bar.empty()) break;
                sum += (min(bar.top().second, curHeight) - lastHeight) * (i - bar.top().first - 1);
            }
            bar.push(make_pair(i, curHeight));
            i++;
        }

        return sum;
    }
};