class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int cnt = 0;
        for (int i = 0; i < guess.size(); i++) {
            if (guess[i] == answer[i]) cnt++;
        }

        return cnt;
    }
};