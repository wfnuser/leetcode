class Solution {
public:
    bool isCharacter(char c) {
        if(c>=65&&c<=90 || c>=97&&c<=122 || c >= '0' && c <= '9') return true;
        return false;
    }

    bool equal(char c1, char c2) {
        if (c2>=97&&c2<=122) c2 -= 32;
        if (c1>=97&&c1<=122) c1 -=32;
        return c1 == c2;
    }

    bool isPalindrome(string s) {
        int size = s.size();
        if (size<=1) return true;
        int left = 0;
        int right = size-1;

        while(left < right) {
            while(!isCharacter(s[left]) && left<right) left++;
            while(!isCharacter(s[right]) && left<right) right--;
            if (left<right && !equal(s[left], s[right])) return false;
            left++;
            right--;
        }

        return true;
    }
};