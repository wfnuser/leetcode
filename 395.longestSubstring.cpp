class Solution {
public:
    int k;

    int longestSubstring(string s, int k) {
        this->k = k;
        return cnt(s, 0, s.size()-1);
    }

    int cnt(string &s, int l, int r) {
        unordered_map<char, int> ch;
        for (int i = l; i <= r; i++) {
            ch[s[i]]++;
        }
        int ll = l;
        int rr = r;
        while(ll <= rr && ch[s[ll]] < k) {
            ll++;
        }
        while (ll <= rr && ch[s[rr]] < k) {
            rr--;
        }
        if (rr - ll + 1 < k) return 0;

        int partition = ll;
        while (partition <= rr && ch[s[partition]] >= k) {
            partition++;
        }
        if (partition >= rr) {
            return rr-ll+1;
        }

        return max(cnt(s, ll, partition-1), cnt(s, partition+1, rr));
    }
};