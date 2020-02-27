class Solution {
    public:
        int findNthDigit(int n) {
            if (n < 10) return n;
            long cnt = 0;
            long tens = 1;
            int i = 0;
            
            while(n > cnt) {
                i++;
                cnt += 9*tens*i;
                tens *= 10;
            }
    
            cnt -= 9*(tens/10)*i;
            n = n - cnt;
            int index = (n-1) / i;
            int mod = (n-1) % i;
            int num = tens/10 - 1;
            int target = num + index +1;
    
            string s = to_string(target);
    
            return s[mod] - '0';
        }
    };