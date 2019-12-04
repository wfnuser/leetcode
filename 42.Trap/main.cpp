class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int sum = 0;
        int base = 0;
        
        struct Bar {
            int x;
            int y;
        };
        
        stack<Bar> s;
        
        for (int i = 0; i < size; i++) {
            Bar bar;
            bar.x = i;
            bar.y = height[i];
            while(!s.empty() && s.top().y < bar.y) {
                Bar top = s.top();
                s.pop();
                if (s.empty())
                    break;
                sum = sum + (bar.x - s.top().x - 1) * (min(bar.y, s.top().y) - top.y);
            }
            s.push(bar);
        }
        
        return sum;
    }
};
