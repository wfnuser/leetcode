class Solution {
public:
    vector<int> primes;

    bool isPrime(int n) {
        for (auto prime: primes) {
            if (prime*prime > n) break;
            if (n%prime == 0) {
                return false;
            }
        }
        primes.push_back(n);
        return true;
    }

    int countPrimes(int n) {
        if (n <= 1) return 0;
        if (n == 2) return 0;

        primes.push_back(2);

        int cnt = 1;
        for (int i = 3; i < n; i++) {
            if (isPrime(i)) cnt++;
        }

        return cnt;
    }
};