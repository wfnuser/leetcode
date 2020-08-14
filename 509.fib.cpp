class Solution {
public:
    vector<int> tmp;
    
    int fib(int N) {
        tmp.resize(N+1);
        return gen(N);
    }

    int gen(int N) {
        if (N <= 1) return N;
        return tmp[N] ? tmp[N] : (tmp[N] = gen(N-1) + gen(N-2));
    }
};