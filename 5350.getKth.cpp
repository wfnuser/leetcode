class Solution {
public:
    
    unordered_map<int, int> weight;
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> V;
        for (int i = lo; i <= hi; i++) {
            int step = 0;
            int cur = i;
            while (cur != 1) {
                if (weight[cur]) {
                    step += weight[cur];
                    break;
                } else {
                    step++;
                    if (cur % 2 == 0) {
                        cur = cur / 2;
                    } else {
                        cur = 3*cur + 1;
                    }
                }
            }
            weight[i] = step;
            V.push_back(make_pair(step, i));
        }
        
        sort(V.begin(), V.end());
        
        return V[k-1].second;
    }
};