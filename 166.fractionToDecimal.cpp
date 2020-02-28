class Solution {
public:
    int gcd(long a, long b) {
        return a == 0 ? b : gcd(b%a, a);
    }

    string fractionToDecimal(int numerator, int denominator) {
        int d = gcd(numerator, denominator);
        long lnumerator = (long)numerator / d;
        long ldenominator = (long)denominator / d;

        if (lnumerator % ldenominator == 0) return to_string(lnumerator/ldenominator);
        string ans = "";
        if (lnumerator/abs(lnumerator) * ldenominator/abs(ldenominator) < 0) ans="-";

        lnumerator = abs(lnumerator);
        ldenominator = abs(ldenominator);
        
        if (lnumerator > ldenominator) {
            ans += to_string(lnumerator/ldenominator) + ".";
            lnumerator %= ldenominator;
        } else {
            ans += "0.";
        }

        long cycle = ldenominator;
        
        while(cycle%2 == 0) {
            cycle /= 2;
        }
        while(cycle%5 == 0) {
            cycle /= 5;
        }

        if (cycle > 1) cycle = 1;
        else cycle = 0;

        if (!cycle) {
            cycle = lnumerator*10;
            while(cycle) {
                ans += to_string(cycle/ldenominator);
                cycle %= ldenominator;
                cycle *= 10;
            }
        } else {
            unordered_map<int, int> visited;
            cycle = lnumerator*10;
            while(cycle) {
                if (visited[cycle]) {
                    ans += " ";
                    for (int l = ans.size() - 1; l >= visited[cycle]; l--) {
                        ans[l] = ans[l-1];
                    }
                    ans[visited[cycle]-1] = '(';
                    ans += ")";
                    break;
                }
                ans += to_string(cycle/ldenominator);
                visited[cycle] = ans.length();
                cycle %= ldenominator;
                cycle *= 10;
            }
        }

        return ans;
    }
};