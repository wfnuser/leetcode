class Solution {
public:
    vector<string> ans;



    void dfs(int start, int num, vector<int>& combination) {
        if (start>9 && num != 0) {
            return;
        }
        if (num == 0) {
            int hour = 0;
            int min = 0;
            for (auto e: combination) {
                if (e<=3) {
                    hour += 1<<e;
                }
                if (e>3) {
                    min += 1<<(e-4);
                }
            }
            string minS = to_string(min);
            if (min < 10) minS = "0" + minS;
            if (min > 60) return;
            if (hour >= 12) return;
            ans.push_back(to_string(hour)+":"+minS);
        } else {
            for (int i = start; i <= 9; i++) {
                combination.push_back(i);
                dfs(i+1, num-1, combination);
                combination.pop_back();
            }
        }
    }

    vector<string> readBinaryWatch(int num) {
        vector<int> com;
        dfs(0,num,com);
        return ans;
    }
};