class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int> heap;
        int i = 0;
        heap.push(-1);
        int smallest = -1;
        int last = 0;
        while(i<n) {
            i++;
            smallest = -heap.top();
            if (last == smallest) {i--;heap.pop();continue;}
            last = smallest;
            heap.pop();
            for (auto prime: primes) {
                if (prime > INT_MAX / smallest) break;
                heap.push(-prime*smallest);
            }
        }

        return smallest;
    }
};