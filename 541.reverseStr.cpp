class Solution {
public:

    void reverseRange(string& s, int start, int end) {
        while(start < end) {
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
    }

    string reverseStr(string s, int k) {
        
        int b = 0;

        while(b < s.size()) {
            if (b+k-1 < s.size()) reverseRange(s, b, b+k-1);
            else {
                reverseRange(s, b, s.size()-1);
            }
            b += 2*k;
        }

        return s;
    }
};