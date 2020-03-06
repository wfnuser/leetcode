class Solution {
public:
    string reverseLeftWords(string s, int n) {
        n %= s.size();
        if (n == 0) return s;

        string rear = "";
        string front = "";

        for (int i = 0; i < n; i++) {
            rear += s[i];
        }
        for (int i = n; i < s.size(); i++) {
            front += s[i];
        }

        return front + rear;
    }
};