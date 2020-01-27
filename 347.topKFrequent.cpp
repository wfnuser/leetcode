class Solution {
public:

    // first is frequency
    // second is number
    void quick_sort(vector<pair<int, int>>& list, int l, int r) {
        if (l >= r) return;

        int slow = l;
        int fast = l+1;
        int pivot = list[l].first;
        pair<int, int> pivotP = list[l];

        while(fast <= r) {
            if (list[fast].first > pivot) {
                pair<int, int> tmp = list[fast];
                list[fast] = list[slow+1];
                list[slow+1] = tmp;
                slow++;
                fast++; 
            } else {
                fast++;
            }
        }

        list[l] = list[slow];
        list[slow] = pivotP;

        quick_sort(list, l, slow-1);
        quick_sort(list, slow+1, r);
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (auto num: nums) {
            cnt[num]++;
        }

        vector<pair<int, int>> list;

        for (auto m: cnt) {
            list.push_back(pair<int, int>(m.second, m.first));
        }

        quick_sort(list, 0, list.size()-1);
    
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(list[i].second);
        }

        return ans;
    }
};