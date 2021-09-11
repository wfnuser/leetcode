class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // 攻击力递减 防御力递增 排序
        sort(properties.begin(), properties.end(), [](auto& x, auto& y){return x[0]>y[0] || x[0]==y[0] && x[1]<y[1];});

        int max_def = -1;
        int ans = 0;

        for (auto property: properties) {
            // 攻击力一定不高于之前的 如果之前已经出现过防御力比当前防御值高的
            // 毫无疑问，当前角色为弱角色
            // 那么 是否可能攻击力和之前相等呢🤔？ 因为防御力递增排序，如果攻击力相等，那么当前的防御值不可能小于max
            if (property[1] < max_def) {
                ans++; // 弱角色++
            } else {
                max_def = property[1]; // 更新最大防御值
            }
        }

        return ans;
    }
};
