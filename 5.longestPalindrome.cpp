class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        int start = 0;
        int end = 0;
        int max = 0;
        string ans = "";

        for (int i = 0; i < size; i++) {
            pair<int, int> p = findPalindrome(i,i,s);
            if (p.second-p.first>max) {
                max = p.second-p.first;
                start = p.first;
                end = p.second;
            }
            p = findPalindrome(i,i+1,s);
            if (p.second-p.first>max) {
                max = p.second-p.first;
                start = p.first;
                end = p.second;
            }
        }

        for (int i = start; i<=end; i++) {
            ans += s[i];
        }

        return ans;   
    }

    pair<int, int> findPalindrome(int left, int right, string s) {
        while(left>=0 && right<=s.size()-1 && s[left] == s[right]) {left--; right++;};
        left++;
        right--;
        return make_pair(left, right);
    }

};
