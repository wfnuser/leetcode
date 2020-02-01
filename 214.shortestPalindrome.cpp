class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s);
        reverse(rev.begin(), rev.end());

        string ns = s + "#" + rev;
        int size = ns.size();
        vector<int> pmt(size, 0);
        int i = 1;
        int j = 0;
        while (i < size) {
            if (ns[i] == ns[j]) {
                pmt[i++] = ++j;
            } else if (j == 0) {
                pmt[i++] = 0;
            } else {
                j = pmt[j-1];
            }
        }

        string pre = "";
        pre = s.substr(pmt[size-1], s.size()-pmt[size-1]);
        reverse(pre.begin(), pre.end());
        return pre + s;
    }
};