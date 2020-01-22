class Solution {
public:
    string reverseVowels(string s) {
        int size = s.size();

        int l = 0;
        int r = size-1;

        unordered_map<char, int> m = {{'A', 1}, {'O', 4}, {'E', 9}, {'I', 5}, {'U', 10}, {'a', 40}, {'o', 90}, {'e', 50}, {'i', 100}, {'u', 100}};

        while(l<r) {
            while(!m[s[l]]&&l<r) {l++;}
            while(!m[s[r]]&&l<r) {r--;}
            if (l>=r) break;
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }

        return s;
    }
};